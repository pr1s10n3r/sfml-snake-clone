#include <SFML/Graphics.hpp>

#include "Food.hpp"
#include "Snake.hpp"
#include "Constant.hpp"

int main() {
    const uint16_t screenSize = snake::GRID_CELL_SIZE * snake::GRID_CELL_COUNT;

    auto window = sf::RenderWindow({screenSize, screenSize}, "SFML Snake Clone");
    window.setFramerateLimit(60);

    snake::Food food;
    snake::Snake snake;

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(snake::LIGHT_GREEN_COLOR);

        window.draw(food);
        window.draw(snake);

        window.display();
    }

    return 0;
}