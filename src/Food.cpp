
#include "../include/Food.hpp"

Food::Food(sf::Vector2i pos) : position(pos) {}

bool Food::tryCollect(Snake &snake) const {
    if (snake.body.front() == position) {
        snake.grow();
        return true;
    }
    else return false;
}

//TODO: move to board
void Food::render(sf::RenderWindow &window, Board &board) const{
    sf::RectangleShape shape(sf::Vector2f(board.cellSize, board.cellSize));
    shape.setFillColor(sf::Color::Red);
    board.draw(position, shape, window);
}

Food &Food::operator=(const Food& other) {
    this->position = other.position;
    return *this;
}


