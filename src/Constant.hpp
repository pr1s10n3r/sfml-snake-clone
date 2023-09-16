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

#include <cstdint>
#include <SFML/Graphics/Color.hpp>

namespace snake {
    const uint8_t GRID_CELL_SIZE = 30;
    const uint8_t GRID_CELL_COUNT = 25;
    const uint8_t WINDOW_BORDER_PADDING = 75;

    const sf::Color LIGHT_GREEN_COLOR = {173, 204, 96, 0xFF};
    const sf::Color DARK_GREEN_COLOR = {43, 51, 24, 0xFF};
} // namespace snake