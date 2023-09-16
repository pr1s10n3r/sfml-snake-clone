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

#include "Game.hpp"

#include <iostream>
#include "Constant.hpp"

namespace snake {
    Game::Game() : snake(Snake()), food(Food()), pause(false) {
        bool loaded = font.loadFromFile("../assets/fonts/VCR_OSD_MONO_1.001.ttf");
        if (!loaded) {
            std::cerr << "Could not load font" << std::endl;
        }
    }

    void Game::draw(sf::RenderTarget &target, sf::RenderStates state) const {
        sf::Text title("Snake Clone", font);
        title.setPosition(snake::WINDOW_BORDER_PADDING - 5, 20);
        title.setFillColor(snake::DARK_GREEN_COLOR);

        target.draw(title);
        target.draw(getWindowFrame());
        target.draw(getScoreText());

        target.draw(food);
        target.draw(snake);
    }

    void Game::update() {
        if (!pause) {
            if (clock.getElapsedTime().asSeconds() >= 0.2) {
                clock.restart();
                snake.update();

                snakeEat();
                snakeCollisions();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && snake.getDirection().y != 1) {
                snake.goUp();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && snake.getDirection().x != 1) {
                snake.goLeft();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && snake.getDirection().y != -1) {
                snake.goDown();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && snake.getDirection().x != -1) {
                snake.goRight();
            }
        }
    }

    void Game::snakeEat() {
        if (snake.getHeadPosition() == food.getPosition()) {
            food.moveToRandomPosition(snake.getBody());
            snake.grow();
            ++score;
        }
    }

    void Game::snakeCollisions() {
        if (snake.getHeadPosition().x == snake::GRID_CELL_COUNT || snake.getHeadPosition().x < 0) {
            gameOver();
        }
        if (snake.getHeadPosition().y == snake::GRID_CELL_COUNT || snake.getHeadPosition().y < 0) {
            gameOver();
        }
        if (snake.isEatingItself()) {
            gameOver();
        }
    }

    void Game::gameOver() {
        snake.reset();
        food.moveToRandomPosition(snake.getBody());
        pause = true;
        score = 0;
    }

    sf::RectangleShape Game::getWindowFrame() const {
        sf::RectangleShape frame({
                                         (snake::GRID_CELL_SIZE * snake::GRID_CELL_COUNT) + 10,
                                         (snake::GRID_CELL_SIZE * snake::GRID_CELL_COUNT) + 10
                                 });

        frame.setPosition(snake::WINDOW_BORDER_PADDING - 5, snake::WINDOW_BORDER_PADDING - 5);
        frame.setOutlineColor(snake::DARK_GREEN_COLOR);
        frame.setOutlineThickness(5.0f);
        frame.setFillColor(sf::Color::Transparent);
        return frame;
    }

    sf::Text Game::getScoreText() const {
        sf::Text scoreText(std::to_string(score), font);
        scoreText.setPosition(snake::WINDOW_BORDER_PADDING - 5,
                              snake::WINDOW_BORDER_PADDING + 10 + (snake::GRID_CELL_SIZE * snake::GRID_CELL_COUNT));
        scoreText.setFillColor(snake::DARK_GREEN_COLOR);
        return scoreText;
    }
} // namespace snake