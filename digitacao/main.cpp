#include <iostream>
#include <SFML/Graphics.hpp>

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