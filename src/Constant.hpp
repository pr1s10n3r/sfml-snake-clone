#pragma once

#include <cstdint>
#include <SFML/Graphics/Color.hpp>

namespace snake {
    const uint8_t GRID_CELL_SIZE = 30;
    const uint8_t GRID_CELL_COUNT = 25;

    const sf::Color LIGHT_GREEN_COLOR = {173, 204, 96, 0xFF};
    const sf::Color DARK_GREEN_COLOR = {43, 51, 24, 0xFF};
} // namespace snake