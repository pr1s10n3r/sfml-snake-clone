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

#include "Snake.hpp"

#include "Constant.hpp"

namespace snake {
    void Snake::draw(sf::RenderTarget &target, sf::RenderStates state) const {
        for (const auto &segment: body) {
            sf::RectangleShape shape({snake::GRID_CELL_SIZE, snake::GRID_CELL_SIZE});
            shape.setPosition((float) segment.x * snake::GRID_CELL_SIZE + snake::WINDOW_BORDER_PADDING,
                              (float) segment.y * snake::GRID_CELL_SIZE + snake::WINDOW_BORDER_PADDING);
            shape.setFillColor(snake::DARK_GREEN_COLOR);
            target.draw(shape);
        }
    }

    void Snake::update() {
        body.pop_back();
        body.push_front(body.front() + direction);
    }

    void Snake::reset() {
        body = {
                sf::Vector2i{6, 9},
                sf::Vector2i{5, 9},
                sf::Vector2i{4, 9},
        };
        direction = {1, 0};
    }

    void Snake::grow() {
        body.push_front(body.front() + direction);
    }

    bool Snake::isEatingItself() const {
        auto headless = body;
        headless.pop_front();

        return std::any_of(headless.cbegin(), headless.cend(), [&](sf::Vector2i segment) -> bool {
            return segment == body.front();
        });
    }
} // namespace snake