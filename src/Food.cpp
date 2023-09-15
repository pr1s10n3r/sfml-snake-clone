#include "Food.hpp"

#include <random>
#include "Constant.hpp"
#include <SFML/Graphics.hpp>

namespace snake {
    Food::Food() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(0, snake::GRID_CELL_COUNT - 1);

        position.x = uni(rng);
        position.y = uni(rng);
    }

    void Food::draw(sf::RenderTarget &target, sf::RenderStates state) const {
        sf::RectangleShape shape({GRID_CELL_SIZE, GRID_CELL_SIZE});
        shape.setPosition((float) position.x * snake::GRID_CELL_SIZE, (float) position.y * GRID_CELL_SIZE);
        shape.setFillColor(foodColor);
        target.draw(shape);
    }
} // namespace snake