#include "Snake.hpp"

#include "Constant.hpp"

namespace snake {
    void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const {
        for (const auto &segment: body) {
            sf::RectangleShape shape({snake::GRID_CELL_SIZE, snake::GRID_CELL_SIZE});
            shape.setPosition((float) segment.x * snake::GRID_CELL_SIZE, (float) segment.y * snake::GRID_CELL_SIZE);
            shape.setFillColor(snake::DARK_GREEN_COLOR);
            target.draw(shape);
        }
    }
} // namespace snake