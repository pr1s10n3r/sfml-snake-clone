#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {
    class Food : public sf::Drawable {
    public:
        Food();

        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

    private:
        sf::Vector2i position;
        const sf::Color foodColor = {0x99, 0x03, 0x05, 0xFF};
    };
} // namespace snake
