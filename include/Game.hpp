
#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "Food.hpp" // this includes board and snake

#define WINDOW_SIZE 800

class Game {
public:
    Game(Snake &player, Board &level, Food& point);
    void run();
private:
    Board &level;
    Snake &playerActor;
    Food &point;
    int points = 0;

    void processInput(sf::RenderWindow &window);
};


#endif //SNAKE_GAME_HPP
