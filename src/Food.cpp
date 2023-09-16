/*
 * Copyright (C) 2023 Alvaro Stagg. [alvarostagg@duck.com]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Food.hpp"

#include <random>
#include "Constant.hpp"
#include <SFML/Graphics.hpp>

namespace snake {
    Food::Food() : position(getRandomPosition()) {}

    sf::Vector2i Food::getRandomPosition() const {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(0, snake::GRID_CELL_COUNT - 1);
        return {uni(rng), uni(rng)};
    }

    bool Food::isCollidingWithSnakeBody(sf::Vector2i newPositionCandidate, const std::deque<sf::Vector2i> &snakeBody) {
        return std::any_of(snakeBody.cbegin(), snakeBody.cend(), [&](sf::Vector2i segment) -> bool {
            return segment == newPositionCandidate;
        });
    }

    void Food::moveToRandomPosition(const std::deque<sf::Vector2i> &snakeBody) {
        sf::Vector2i newPositionCandidate = getRandomPosition();
        while (isCollidingWithSnakeBody(newPositionCandidate, snakeBody)) {
            newPositionCandidate = getRandomPosition();
        }
        position = newPositionCandidate;
    }

    void Food::draw(sf::RenderTarget &target, sf::RenderStates state) const {
        sf::RectangleShape shape({GRID_CELL_SIZE, GRID_CELL_SIZE});
        shape.setPosition((float) position.x * snake::GRID_CELL_SIZE + snake::WINDOW_BORDER_PADDING,
                          (float) position.y * GRID_CELL_SIZE + snake::WINDOW_BORDER_PADDING);
        shape.setFillColor(foodColor);
        target.draw(shape);
    }
} // namespace snake