#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <ctime>

const auto yellow = sf::Color(232, 235, 56);
const auto light_gray = sf::Color(83, 83, 83);

/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
// Handles how the text works on a window
struct Pincel {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    // Load and set the font used with the referenced window
    Pincel(sf::RenderWindow& window) : window(window) {
        if (!font.loadFromFile("Ubuntu/Ubuntu-Regular.ttf")) {
            std::cout << "Font didn't load sucessfully\n";
        } else {
            std::cout << "Font sucessfully loaded\n";
        }
        text.setFont(font);
    }

    // Gets the string, coordinates x and y, the size of the font and the filling color of the text
    // Prints a text on the window
    void write(std::string string, int x, int y, int size, sf::Color color) {
        text.setString(string);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
// Handles how bubbles works on a window 
struct Bubble {
    int x;
    int y;
    char letter;
    int speed;

    static const int radius { 10 };
    bool alive { true };

    // Enter the coordinates x and y, enter the letter inside the bubble and enter the speed as an integer
    // Default constructor for the bubble
    Bubble(int x, int y, char letter, int speed) : 
        x(x), y(y), letter(letter), speed(speed) {
    }

    // Updates the fall of bubble accordingly to it's speed
    void update() {
        this->y += this->speed;
    }

    // Draws the bubble to the referenced window
    void draw(sf::RenderWindow& window) {
        sf::CircleShape bubble(Bubble::radius, 500);
        bubble.setPosition(x, y);
        bubble.setFillColor(sf::Color::White);
        window.draw(bubble);

        static Pincel pincel(window);
        pincel.write(std::string(1, letter), x + 0.4 * Bubble::radius, y, Bubble::radius * 1.5, sf::Color::Black);
    }
};
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
// Handles multiple bubbles in a window
struct Board {
    sf::RenderWindow& window;
    std::vector<Bubble> bubbles;
    Pincel pincel;
    int hits { 0 };
    int misses { 0 };

    // Add bubbles to a vector and set the referenced window that'll be used
    Board(sf::RenderWindow& window): window(window), pincel(window) {
        bubbles.push_back(Bubble(100, 100, 'L', 2));
        bubbles.push_back(Bubble(200, 100, 'A', 2));
        bubbles.push_back(Bubble(400, 100, 'Z', 3));
        bubbles.push_back(Bubble(700, 100, 'S', 1));
    }

    // Checks if there is the need of a new bubble and updates the timer
    bool check_new_bubble() {
        static const int new_bubble_timeout { 60 };
        static int new_bubble_timer { 0 };

        new_bubble_timer--;
        if(new_bubble_timer <= 0) {
            new_bubble_timer = new_bubble_timeout;
            return true;
        }
        return false;
    }

    // Adds a new random bubble
    void add_new_bubble() {
        srand(time(0));
        int x = rand() % ((int) this->window.getSize().x - 2 * Bubble::radius);
        int y = - 2 * Bubble::radius;
        int speed = rand() % 10 + 1;
        char letter = rand() % 26 + 'A';
        bubbles.push_back(Bubble(x, y, letter, speed));
    }
     
    // Updates all the bubbles of the vector by reference
    void update() {
        if (this->check_new_bubble()) {
            this->add_new_bubble();
        }
        for (Bubble& bubble : bubbles) {
            bubble.update();
        }
        mark_outside_bubble();
        remove_dead_bubbles();
    }

    // Remove bubbles marked as dead 
    void remove_dead_bubbles() {
        std::vector<Bubble> vivas;
        for (Bubble& bubble : bubbles) {
            if (bubble.alive) {
                vivas.push_back(bubble);
            }
        }
        this->bubbles = vivas;
    }

    // Mark bubbles outside of the board as dead
    void mark_outside_bubble() {
        for (Bubble& bubble : bubbles) {
            if (bubble.y + 2 * Bubble::radius > (int) this->window.getSize().y) {
                bubble.alive = false;
                this->misses++;
            }
        }
    }

    // Mark bubble by char input, if they are equal values
    void mark_by_hit(char letter) {
        for (Bubble& bubble : bubbles) {
            if (bubble.letter == letter) {
                bubble.alive = false;
                this->hits++;
                break;
            }
        }
    }

    // Draws the gameplay() screen itens
    void gameplay_draw() {
        pincel.write("Hits: " + std::to_string(this->hits) + " Misses: " + std::to_string(this->misses), 10, 10, 20, yellow);
        pincel.write("Size: " + std::to_string(this->bubbles.size()),10, 30, 20, yellow);
        for (Bubble& bubble : bubbles) {
            bubble.draw(window);
        }
    }

    // Draws the game_over() screen itens
    void game_over_draw() {
        pincel.write("GAME OVER!", 190, 200, 70, yellow);
        pincel.write("Press 'Space' to restart the game", 215, 550, 23, yellow);
        pincel.write("Press 'Esc'", 10, 10, 16, yellow);
        pincel.write("to exit", 20, 26, 16, yellow);
    }
    
};
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// Set up the window to run the game and handdles it's events
struct Game {
    sf::RenderWindow window;
    Board board;
    std::function<void()> on_update;
    std::function<void()> event_process;
    int videoWidth { 800 };
    int videoHeight { 600 };

    // Sets the window and the board to handdle the bubbles as the default constructor
    Game() : window(sf::VideoMode(800, 600), "Bubble Type"), board(window) {
        this->on_update = [&]() {
            this->gameplay();
        };
        this->event_process = [&]() {
            this->gameplay_event_process();
        };
        window.setFramerateLimit(60);
    };

    // Sets the window, width and height, and the board to handdle the bubbles
    Game(int width, int height) : 
        window(sf::VideoMode(width, height), "Bubble Type"), board(window), videoWidth(width), videoHeight(height) {
        this->on_update = [&]() {
            this->gameplay();
        };
        window.setFramerateLimit(60);
    };

    // Process the available events to the gameplay() screen
    void gameplay_event_process() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } 
            } else if (event.type == sf::Event::TextEntered) {
                char code = static_cast<char>(event.text.unicode);
                code = toupper(code);
                board.mark_by_hit(code);
            }
        }
    }

    // Draws the gameplay board
    void gameplay() {
        board.update();
        window.clear(light_gray);
        board.gameplay_draw();
        window.display();
        if (board.misses > 3) {
            this->on_update = [&]() {
                this->game_over();
            };
            this->event_process = [&]() {
                this->game_over_event_process();
            };
        }
    }

    // Clears the previous game stats and changes to gameplay() screen
    void restart_gameplay() {
        board.misses = 0;
        board.bubbles.clear();
        this->on_update = [&]() {
            this->gameplay();
        };
        this->event_process = [&]() {
            this->gameplay_event_process();
        };
    }

    // Process the available events of the game_over() screen
    void game_over_event_process() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    restart_gameplay();
                }
            }
        }
    }

    // Draws Game Over on the screen
    void game_over() {
        window.clear(light_gray);
        board.game_over_draw();
        window.display();
    }

    // Encapsulates the event processing and the drawing process
    void main_loop() {
        while (window.isOpen()) {
            event_process();
            on_update();
        }
    }
};




int main() {
    Game game;
    game.main_loop();

    return 0;
}