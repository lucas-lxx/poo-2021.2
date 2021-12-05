#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

struct Pincel {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    Pincel(sf::RenderWindow& window) : window(window) {
        if (!font.loadFromFile("Ubuntu/Ubuntu-Regular.ttf")) {
            std::cout << "Font didn't load sucessfully\n";
        } else {
            std::cout << "Font sucessfully loaded\n";
        }
        text.setFont(font);
    }

    void write(std::string string, int x, int y, int size, sf::Color color) {
        text.setString(string);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};

struct Bubble {
    int x;
    int y;
    char letter;
    int speed;

    static const int radius { 10 };
    bool alive { true };

    Bubble(int x, int y, char letter, int speed) : 
        x(x), y(y), letter(letter), speed(speed) {
    }

    void update() {
        this->y += this->speed;
    }

    void draw(sf::RenderWindow& window) {
        sf::CircleShape bubble(Bubble::radius, 500);
        bubble.setPosition(x, y);
        bubble.setFillColor(sf::Color::White);
        window.draw(bubble);

        static Pincel pincel(window);
        pincel.write(std::string(1, letter), x + 0.4 * Bubble::radius, y, Bubble::radius * 1.5, sf::Color::Black);
    }
};

struct Board {
    sf::RenderWindow& window;
    std::vector<Bubble> bubbles;
    const int new_bubble_timeout { 30 };
    int new_bubble_timer { 0 };
    int hits { 0 };
    int misses { 0 };

    Board(sf::RenderWindow& window): window(window) {
        bubbles.push_back(Bubble(100, 100, 'L', 2));
        bubbles.push_back(Bubble(200, 100, 'A', 2));
        bubbles.push_back(Bubble(400, 100, 'Z', 3));
        bubbles.push_back(Bubble(700, 100, 'S', 1));
    }

    void update() {
        for (Bubble& bubble : bubbles) {
            bubble.update();
        }
    }

    void draw() {
        for (Bubble& bubble : bubbles) {
            bubble.draw(window);
        }
    }
};

struct Game {
    sf::RenderWindow window;

    Game() : window(sf::VideoMode(800, 600), "Bubble Type") {
        window.setFramerateLimit(30);
    };

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

    void draw() {
        window.clear(sf::Color::Black);
        static Board bubble(window);
        bubble.update();
        bubble.draw();
        window.display();
    }

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