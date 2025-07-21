#include <iostream>
#include "../include/Game.hpp"

int main(){

    Board board(WINDOW_SIZE, 5);
    Snake snake({3,  2});
    Food food({2, 2});

    Game game(snake, board, food);
    game.run();



    return 0;
}