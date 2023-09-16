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

#include "Snake.hpp"
#include "Food.hpp"

namespace snake {
    class Game : public sf::Drawable {
    public:
        Game();

        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

        void update();

        void unpause() { pause = false; };

        [[nodiscard]] sf::RectangleShape getWindowFrame() const;

        [[nodiscard]] sf::Text getScoreText() const;

    private:
        bool pause;
        uint8_t score;

        Snake snake;
        Food food;
        sf::Clock clock;
        sf::Font font;

        void snakeEat();

        void snakeCollisions();

        void gameOver();
    };
} // namespace snake