#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

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
    const int new_bubble_timeout { 30 };
    int new_bubble_timer { 0 };
    int hits { 0 };
    int misses { 0 };

    // Add bubbles to a vector and set the referenced window that'll be used
    Board(sf::RenderWindow& window): window(window) {
        bubbles.push_back(Bubble(100, 100, 'L', 2));
        bubbles.push_back(Bubble(200, 100, 'A', 2));
        bubbles.push_back(Bubble(400, 100, 'Z', 3));
        bubbles.push_back(Bubble(700, 100, 'S', 1));
    }

    // Updates all the bubbles of the vector
    void update() {
        for (Bubble& bubble : bubbles) {
            bubble.update();
        }
    }

    // Draws on referenced the window all the bubbles of the vector
    void draw() {
        for (Bubble& bubble : bubbles) {
            bubble.draw(window);
        }
    }
};

// Set up the window to run the game and handdles it's events
struct Game {
    sf::RenderWindow window;

    // Sets the window mode and it's tittle
    Game() : window(sf::VideoMode(800, 600), "Bubble Type") {
        window.setFramerateLimit(30);
    };

    // Process the events
    void process_events() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
    }

    // Draws the elements on window
    void draw() {
        window.clear(sf::Color::Black);
        static Board bubble(window);
        bubble.update();
        bubble.draw();
        window.display();
    }

    // Encapsulates the event processing and the drawing process
    void main_loop() {
        while (window.isOpen()) {
            process_events();
            draw();
        }
    }


};

int main() {
    Game game;
    game.main_loop();

    return 0;
}