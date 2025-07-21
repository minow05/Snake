
#include <iostream>
#include "../include/Board.hpp"

Board::Board(int size, int boardSize) : size(size), boardSize(boardSize) {
    cellSize = size / boardSize;
    std::cout << "Board created\nboard size: " << boardSize << "\ncell size: " << cellSize << "\npixel size: " << size << "\n";
}

sf::Vector2f Board::cellToPixel(sf::Vector2i cell) const {
    return sf::Vector2f{static_cast<float>(cell.x * cellSize), static_cast<float>(cell.y * cellSize)};
}

//TODO: render cells + this->map
void Board::render(sf::RenderWindow &window) const {
    for (int i = 0; i <= size; i++) {
        sf::RectangleShape border({BORDER_THICKNESS , static_cast<float>(boardSize * cellSize)});
        border.setFillColor(sf::Color::Black);
        border.setPosition(sf::Vector2f(i * cellSize, 0));
        window.draw(border);
    }
    for (int i = 0; i <= size; i++) {
        sf::RectangleShape border({static_cast<float>(boardSize * cellSize), BORDER_THICKNESS});
        border.setFillColor(sf::Color::Black);
        border.setPosition(sf::Vector2f(0, i * cellSize));
        window.draw(border);
    }
}

void Board::draw(sf::Vector2i pos, sf::RectangleShape shape, sf::RenderWindow &window) const {
    if (pos.x < 0 || pos.x >= boardSize || pos.y < 0 || pos.y >= boardSize) {
        throw std::out_of_range("Board out of bounds access.");
    }
    shape.setSize({shape.getSize().x - BORDER_THICKNESS, shape.getSize().y - BORDER_THICKNESS});
    shape.setPosition({cellToPixel(pos).x + BORDER_THICKNESS, cellToPixel(pos).y + BORDER_THICKNESS});
    window.draw(shape);
}

void Board::place(sf::Vector2i position, CellState object) {
    map[position.x][position.y] = object;
}

void Board::clear(sf::Vector2i position) {
    map[position.x][position.y] = CellState::empty;
}
