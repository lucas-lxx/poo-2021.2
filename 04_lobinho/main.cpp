#include <iostream>
#include <SFML/Graphics.hpp>

void setSize(sf::Sprite &sprite, int width, int height) {
    sf::FloatRect dim = sprite.getLocalBounds();
    sprite.setScale(float(width) / dim.width, float(height) / dim.height);
}

struct Entity {
    int mb_x { 0 };
    int mb_y { 0 };
    int mb_step { 0 };
    sf::Sprite mb_sprite;

    Entity(int x, int y, int step, sf::Texture& texture):
        mb_x(x), mb_y(y), mb_step(step), mb_sprite(texture) {
    }

    void draw(sf::RenderWindow& window) {
        this->mb_sprite.setPosition(mb_x * mb_step,  mb_y * mb_step);
        setSize(this->mb_sprite, mb_step, mb_step);
        window.draw(this->mb_sprite);
    }

    // int window height int window width
    void wraparound(int height, int width){
        if (this->mb_y < 0) {
            this->mb_y = height - 1;
        } else if (this->mb_y > height - 1) {
            this->mb_y = 0;
        } else if (this->mb_x < 0) {
            this->mb_x = width - 1;
        } else if (this->mb_x > width - 1) {
            this->mb_x = 0;
        }
    }
};

struct Board {
    int mb_height { 0 };
    int mb_width { 0 };
    int mb_step { 0 };
    sf::Sprite mb_sprite;
    sf::RectangleShape mb_rect;

    Board(int height, int width, int step, sf::Texture& texture):
        mb_height(height), mb_width(width), mb_step(step), mb_sprite(texture) {
        setSize(this->mb_sprite, width * step, height * step);
        this->mb_sprite.setPosition(0 , 0);

        this->mb_rect.setSize(sf::Vector2f(step, step));
        this->mb_rect.setFillColor(sf::Color::Transparent);
        this->mb_rect.setOutlineColor(sf::Color::White);
        this->mb_rect.setOutlineThickness(2);
    }

    void drawWithGrid(sf::RenderWindow& window) {
        window.draw(this->mb_sprite);
        for (int i = 0; i < mb_width; i++) {
            for (int j = 0; j < mb_height; j++) {
                mb_rect.setPosition(i * mb_step, j * mb_step);
                window.draw(mb_rect);
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(this->mb_sprite);
    }
};


void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys) {
    if (key == move_keys[0]) {
        entity.mb_x--;
    } else if (key == move_keys[1]) {
        entity.mb_x++;
    } else if (key == move_keys[2]) {
        entity.mb_y--;
    } else if (key == move_keys[3]) {
        entity.mb_y++;
    }
}

sf::Texture loadTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "Error loading texture" << '\n';
        exit(1);
    }
    return texture;
}

template <typename T>
bool equal(T A, T B) {
    return A == B ? true : false;
}

int main() 
{
    std::vector<sf::Keyboard::Key> arrow_keys { sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down };
    std::vector<sf::Keyboard::Key> vim_move_keys { sf::Keyboard::H, sf::Keyboard::L, sf::Keyboard::K, sf::Keyboard::J };
    std::vector<sf::Keyboard::Key> wasd_move_keys { sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S };

    sf::Texture wolf_texture { loadTexture("images/lobol.png") };
    sf::Texture bunny_texture { loadTexture("images/coelho.png") };
    sf::Texture board_texture { loadTexture("images/grama.jpg")};
    sf::Texture game_over_texture { loadTexture("images/game-over.png") };

    const int STEP { 100 };
    
    Entity wolf(1, 1, STEP, wolf_texture);
    Entity bunny(3, 3, STEP, bunny_texture);
    Board board(6, 8, STEP, board_texture);
    Board game_over(board.mb_height, board.mb_width, STEP, game_over_texture);
    std::cout << board.mb_width << " " << board.mb_height << '\n';

    sf::RenderWindow window(sf::VideoMode(board.mb_width * STEP, board.mb_height * STEP), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } else if (event.key.code == sf::Keyboard::Space){
                    bunny.mb_x = 3;
                    bunny.mb_y = 3;
                    wolf.mb_x = 1;
                    wolf.mb_y = 1;
                } else if (!equal(bunny.mb_x, wolf.mb_x) || !equal(bunny.mb_y, wolf.mb_y)){
                    moveEntity(event.key.code, wolf, vim_move_keys);
                    moveEntity(event.key.code, wolf, arrow_keys);
                    moveEntity(event.key.code, bunny, wasd_move_keys);
                }
            } 
        }

        bunny.wraparound(board.mb_height, board.mb_width);
        wolf.wraparound(board.mb_height, board.mb_width);
    
        bunny.mb_sprite.setPosition(bunny.mb_x, bunny.mb_y);
        wolf.mb_sprite.setPosition(wolf.mb_x, wolf.mb_y);
        if (bunny.mb_x == wolf.mb_x && bunny.mb_y == wolf.mb_y){
            window.clear();
            game_over.draw(window);
            window.display();
        } else {
            window.clear();
            board.drawWithGrid(window);
            bunny.draw(window);
            wolf.draw(window);
            window.display();
        }
    }

    return 0;
}