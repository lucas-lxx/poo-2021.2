#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

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
        static const int new_bubble_timeout { 30 };
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
        int x = rand() % ((int) this->window.getSize().x - 2 * Bubble::radius);
        int y = - 2 * Bubble::radius;
        int speed = rand() % 5 + 1;
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

    // Draws on the referenced window
    void draw() {
        pincel.write("Hits: " + std::to_string(this->hits) + " Misses: " + std::to_string(this->misses), 10, 10, 20, sf::Color::Yellow);
        pincel.write("Size: " + std::to_string(this->bubbles.size()),10, 30, 20, sf::Color::White);
        for (Bubble& bubble : bubbles) {
            bubble.draw(window);
        }
    }

    
};




// Set up the window to run the game and handdles it's events
struct Game {
    sf::RenderWindow window;
    Board board;
    std::function<void()> on_update;

    // Sets the window and the board to handdle the bubbles
    Game() : window(sf::VideoMode(800, 600), "Bubble Type"), board(window) {
        this->on_update = [&]() {
            this->gameplay();
        };
        window.setFramerateLimit(30);
    };

    // Process the events
    void process_events() {
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

    // Draws the elements on window
    void gameplay() {
        board.update();
        window.clear(sf::Color::Black);
        board.draw();
        window.display();
    }

    // Encapsulates the event processing and the drawing process
    void main_loop() {
        while (window.isOpen()) {
            process_events();
            on_update();
        }
    }
};




int main() {
    Game game;
    game.main_loop();

    return 0;
}