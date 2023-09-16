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

#pragma once

#include <deque>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {
    class Food : public sf::Drawable {
    public:
        Food();

        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

        void moveToRandomPosition(const std::deque<sf::Vector2i> &snakeBody);

        [[nodiscard]] inline sf::Vector2i getPosition() const { return position; }

    private:
        sf::Vector2i position;
        const sf::Color foodColor = {0x99, 0x03, 0x05, 0xFF};

        [[nodiscard]] sf::Vector2i getRandomPosition() const;

        bool isCollidingWithSnakeBody(sf::Vector2i newPositionCandidate, const std::deque<sf::Vector2i> &snakeBody);
    };
} // namespace snake
