
#include <iostream>
#include "../include/Snake.hpp"

void Snake::grow() {
    isFed = true;
}

void Snake::move(Board &board) {
    sf::Vector2 head = body.front();

    switch (direction) {
        case Direction::right:
            if (head.x + 1 >= board.boardSize) body.emplace_front(0, head.y); // out of bounds scenario
            else body.emplace_front(head.x + 1, head.y);
            break;
        case Direction::left:
            if (head.x - 1 < 0) body.emplace_front(board.boardSize - 1, head.y);
            else body.emplace_front(head.x - 1, head.y);
            break;
        case Direction::up:
            if (head.y + 1 >= board.boardSize) body.emplace_front(head.x, 0);
            else body.emplace_front(head.x, head.y + 1);
            break;
        case Direction::down:
            if (head.y - 1 < 0) body.emplace_front(head.x, board.boardSize - 1);
            else body.emplace_front(head.x, head.y - 1);
            break;
        default:
            break;
    }
    board.place(body.front(), type);
    // manage food logic
    if (!isFed){
        board.clear(body.back());
        body.pop_back();
    }
    isFed = false;
}

Snake::Snake(sf::Vector2i startPosition, Board &board) {
    body.emplace_front(startPosition);
    board.place(body.front(), type);
    std::cout << "Snake created\n" << "position: " << startPosition.x << ", " << startPosition.y << "\n";;
}

void Snake::setDirection(Snake::Direction d) {
    // it is to prevent reversal
    if ((direction == Direction::left && d != Direction::right) ||
        (direction == Direction::right && d != Direction::left) ||
        (direction == Direction::up && d != Direction::down) ||
        (direction == Direction::down && d != Direction::up)) {
        direction = d;
    }
}

bool Snake::checkIfTouch() {
    sf::Vector2i head = body.front();
    auto it = std::next(body.begin());  // skip first element
    for (; it != body.end(); ++it) {
        const auto& segment = *it;
        if (segment.x == head.x && segment.y == head.y) {
            return true;
        }
    }
    return false;

}
