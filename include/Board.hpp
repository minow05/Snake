
#ifndef SNAKE_BOARD_HPP
#define SNAKE_BOARD_HPP

#include <SFML/Graphics.hpp>

#define BOARD_SIZE 20
#define WINDOW_SIZE 800

class Board {
private:
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> map;
    int height, width, cellSize;
public:
    Board (int height, int width, int cellSize);
    void render (sf::RenderWindow& window);
};


#endif //SNAKE_BOARD_HPP
