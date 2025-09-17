#include <iostream>
#include "../include/Game.hpp"

int main(){

    Board board(WINDOW_SIZE, 8);
    Snake snake({1,  1}, board);
    Food food({1, 0}, board);

    Game game(snake, board, food);

    return 0;
}