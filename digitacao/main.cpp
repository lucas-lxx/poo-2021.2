#include <iostream>
#include <SFML/Graphics.hpp>

struct Pincel {
    sf::Font font;
    sf::Text text;
    sf::RenderWindow& window;

    Pincel(sf::RenderWindow& window) : window(window) {
        if (!font.loadFromFile("Ubuntu/Ubuntu-Regular.ttf")) {
            std::cout << "Font didn't load sucessfully\n";
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

struct Game {
    sf::RenderWindow window;

    Game() : window(sf::VideoMode(800, 600), "Bubble Type") {
        window.setFramerateLimit(60);
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
        window.clear();
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