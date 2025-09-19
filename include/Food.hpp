
#ifndef SNAKE_FOOD_HPP
#define SNAKE_FOOD_HPP

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Board.hpp"
#include "CellState.hpp"

class Food {
public:
    const CellState type = CellState::food;
    sf::Vector2i position;
    bool tryCollect (Snake &snake, Board &board) const;

    Food(sf::Vector2i pos, Board &board);
    Food();
    explicit Food(Board &board);
    Food& operator=(const Food& other);
};


#endif //SNAKE_FOOD_HPP
