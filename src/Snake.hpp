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
    class Snake : public sf::Drawable {
    public:
        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

        void update();

        bool isEatingItself() const;

        inline void goUp() { direction = {0, -1}; }

        inline void goDown() { direction = {0, 1}; }

        inline void goLeft() { direction = {-1, 0}; }

        inline void goRight() { direction = {1, 0}; }

        [[nodiscard]] inline sf::Vector2i getDirection() const { return direction; }

        [[nodiscard]] inline sf::Vector2i getHeadPosition() const { return body.front(); }

        [[nodiscard]] inline std::deque<sf::Vector2i> getBody() const { return body; }

        void grow();

        void reset();

    private:
        sf::Vector2i direction = {1, 0};
        std::deque<sf::Vector2i> body{
                sf::Vector2i{6, 9},
                sf::Vector2i{5, 9},
                sf::Vector2i{4, 9},
        };
    };
} // namespace snake