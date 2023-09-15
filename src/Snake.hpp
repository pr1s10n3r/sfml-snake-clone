#pragma once

#include <deque>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace snake {
    class Snake : public sf::Drawable {
    public:
        void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

    private:
        std::deque<sf::Vector2i> body{
                sf::Vector2i{6, 9},
                sf::Vector2i{5, 9},
                sf::Vector2i{4, 9},
        };
    };
} // namespace snake