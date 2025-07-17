
#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <deque>
#include "SFML/Graphics.hpp"

class Snake {
private:
    enum class Direction {right, left, up, down};
    Direction direction;
public:
    Snake(sf::Vector2i startPosition);

    std::deque<sf::Vector2i> body;
    bool isFed;

    void grow();
    void move();
    void setDirection(Direction d);

    void render (sf::RenderWindow& window);
};


#endif //SNAKE_SNAKE_HPP
