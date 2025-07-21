
#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <deque>
#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "CellState.hpp"

class Snake {
public:
    const CellState type = CellState::snake;
    enum class Direction {right, left, up, down};
    explicit Snake(sf::Vector2i startPosition);

    std::deque<sf::Vector2i> body;
    bool isFed = false;

    void grow();
    void move(Board &board);
    void setDirection(Direction d);
    bool checkIfTouch();

    void render (sf::RenderWindow& window, Board &board);
private:
    Direction direction = Direction::up;
};


#endif //SNAKE_SNAKE_HPP
