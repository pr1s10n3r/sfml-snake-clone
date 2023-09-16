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

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Constant.hpp"

int main() {
    const uint16_t screenSize = (2 * snake::WINDOW_BORDER_PADDING) + snake::GRID_CELL_SIZE * snake::GRID_CELL_COUNT;

    auto window = sf::RenderWindow({screenSize, screenSize}, "SFML Snake Clone");
    window.setFramerateLimit(60);

    snake::Game game;

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                game.unpause();
            }
        }

        game.update();

        window.clear(snake::LIGHT_GREEN_COLOR);
        window.draw(game);
        window.display();
    }

    return 0;
}