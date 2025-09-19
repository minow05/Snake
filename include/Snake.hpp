
#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <deque>
#include <SFML/Graphics.hpp>
#include "CellState.hpp"

class Snake {
public:
    const CellState type = CellState::snake;
    enum class Direction {right, left, up, down};
    Snake();

    std::deque<sf::Vector2i> body;
    bool isFed = false;

    void grow();
    void setDirection(Direction d);
    bool checkIfTouch();

    Direction direction = Direction::up;
};


#endif //SNAKE_SNAKE_HPP
