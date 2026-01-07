
#ifndef SNAKE_BOARD_HPP
#define SNAKE_BOARD_HPP

#include <SFML/Graphics.hpp>
#include "CellState.hpp"
#include "Snake.hpp"
#include "Food.hpp"

#define BORDER_THICKNESS 2

class Board {

public:
    int cellSize; //px
    Board (int size, int boardSize);
    Board();
    void render(sf::RenderWindow& window) const;
    void draw(sf::Vector2i position, sf::RectangleShape shape, sf::RenderWindow &window) const;
    void place(sf::Vector2i position, CellState object);
    void clear(sf::Vector2i position);
    bool cellIsFree(sf::Vector2i position);
    void snakeEmplace(Snake& snake, sf::Vector2i startPosition);
    void printDebug();
    int boardSize; //int

    void snakeMove(Snake& snake); //TODO: refractor to Snake
//    std::vector<Snake>& players; //TODO: make an owner of players and points
//    std::vector<Food>& points;
private:
    [[nodiscard]] sf::Vector2f cellToPixel(sf::Vector2i cell) const;
    int size; //px
    std::vector<std::vector<CellState>> map;
};


#endif //SNAKE_BOARD_HPP
