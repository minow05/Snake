
#include <iostream>
#include "../include/Food.hpp"

Food::Food(sf::Vector2i pos, Board &board) {
    if (board.cellIsFree(pos)){
        position = pos;
        board.place(position, type);
    }
}

bool Food::tryCollect(Snake &snake, Board &board) const {
    if (snake.body.front() == position) {
        snake.grow();
        return true;
    }
    else return false;
}

Food &Food::operator=(const Food& other) {
    this->position = other.position;
    return *this;
}

Food::Food(Board &board) {
    position = {rand() % board.boardSize, rand() % board.boardSize};
    while (!board.cellIsFree(position)){
        position = {rand() % board.boardSize, rand() % board.boardSize};
    }
    board.place(position, type);
}

Food::Food() {}


