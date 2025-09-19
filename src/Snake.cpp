
#include <iostream>
#include "../include/Snake.hpp"

void Snake::grow() {
    isFed = true;
}

Snake::Snake() {}

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


