
#ifndef SNAKE_BOARD_HPP
#define SNAKE_BOARD_HPP

#include <SFML/Graphics.hpp>
#include "CellState.hpp"

#define BORDER_THICKNESS 2

class Board {
private:
    int size;
    std::vector<std::vector<CellState>> map;
public:
    int cellSize;
    Board (int size, int boardSize);
    void render (sf::RenderWindow& window) const;
    void draw(sf::Vector2i pos, sf::RectangleShape shape, sf::RenderWindow &window) const;
    void place(sf::Vector2i position, CellState object);
    void clear(sf::Vector2i position);
    [[nodiscard]] sf::Vector2f cellToPixel(sf::Vector2i cell) const;

    int boardSize;
};


#endif //SNAKE_BOARD_HPP
