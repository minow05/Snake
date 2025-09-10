
#include <iostream>
#include "../include/Board.hpp"

Board::Board(int size, int boardSize) : size(size), boardSize(boardSize) {
    if (size > 255){
        throw std::invalid_argument("Board size is too big (size cannot be larger than 255).");
    }
    cellSize = size / boardSize;
    std::cout << "Board created\nboard size: " << boardSize << "\ncell size: " << cellSize << "\npixel size: " << size << "\n";
    map = std::vector<std::vector<CellState>>(boardSize, std::vector<CellState>(boardSize, CellState::empty));
}

sf::Vector2f Board::cellToPixel(sf::Vector2i cell) const {
    return sf::Vector2f{static_cast<float>(cell.x * cellSize), static_cast<float>(cell.y * cellSize)};
}


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
    int rowCounter = 0;
    for (auto& row : map){
        int columnCounter = 0;
        for (auto& element : row) {
            sf::RectangleShape shape(sf::Vector2f(cellSize, cellSize));
            switch (element) {
                case CellState::empty:
//                    shape.setFillColor(sf::Color::White);
                    break;
                case CellState::snake:
                    shape.setFillColor(sf::Color::Green);
                    break;
                case CellState::food:
                    shape.setFillColor(sf::Color::Red);
                    break;
            }
            draw(sf::Vector2i{rowCounter, columnCounter}, shape, window);
            columnCounter++;
        }
        rowCounter++;
    }
}

void Board::draw(sf::Vector2i position, sf::RectangleShape shape, sf::RenderWindow &window) const {
    if (position.x < 0 || position.x >= boardSize || position.y < 0 || position.y >= boardSize) {
        std::cout << "ERROR\nAt x = " << position.x << ", y = " << position.y << "\n";
        throw std::out_of_range("Board out of bounds access.");
    }
    shape.setSize({shape.getSize().x - BORDER_THICKNESS, shape.getSize().y - BORDER_THICKNESS});
    shape.setPosition({cellToPixel(position).x + BORDER_THICKNESS, cellToPixel(position).y + BORDER_THICKNESS});
    window.draw(shape);
}

void Board::place(sf::Vector2i position, CellState object) {
    if (position.x < 0 || position.x >= boardSize || position.y < 0 || position.y >= boardSize) {
        std::cout << "ERROR\nat x = " << position.x << ", y = " << position.y << "\n";
        throw std::out_of_range("Board out of bounds access.");
    }
    map[position.x][position.y] = object;
}

void Board::clear(sf::Vector2i position) {
    if (position.x < 0 || position.x >= boardSize || position.y < 0 || position.y >= boardSize) {
        std::cout << "ERROR\nat x = " << position.x << ", y = " << position.y << "\n";
        throw std::out_of_range("Board out of bounds access.");
    }
    map[position.x][position.y] = CellState::empty;
}

bool Board::cellIsFree(sf::Vector2i position) {
    if (position.x < 0 || position.x >= boardSize || position.y < 0 || position.y >= boardSize) {
        std::cout << "ERROR\nat x = " << position.x << ", y = " << position.y << "\n";
        throw std::out_of_range("Board out of bounds access.");
    }
    if (map[position.x][position.y] == CellState::empty) {
        std::cout << "Cell " << position.x << ", " << position.y << " is free\n";
        return true;
    } else {
        return false;
    }
}

void Board::printDebug() {
    for (auto &row : map){
        for (auto &cell : row){
            switch (cell) {
                case CellState::empty:
                    std::cout << "0";
                    break;
                case CellState::snake:
                    std::cout << "S";
                    break;
                case CellState::food:
                    std::cout << "F";
                    break;
            }
        }
        std::cout << "\n";
    }
}
