
#include "../include/Snake.hpp"

void Snake::grow() {
    isFed = true;
}

void Snake::move() {
    sf::Vector2 head = body.front();
    switch (direction) {
        case Direction::right:
            body.emplace_front(head.x + 1, head.y);
        case Direction::left:
            body.emplace_front(head.x - 1, head.y);
        case Direction::up:
            body.emplace_front(head.x, head.y + 1);
        case Direction::down:
            body.emplace_front(head.x, head.y - 1);
    }
    // manage food logic
    if (!isFed){
        body.pop_back();
    }
    isFed = false;
}

Snake::Snake(sf::Vector2i startPosition) {
    body.emplace_front(startPosition);
    setDirection(Direction::up);
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

void Snake::render(sf::RenderWindow &window) {
    for (auto& segment : body){
//        window.draw(sf::) TODO: rendering logic
    }
}
