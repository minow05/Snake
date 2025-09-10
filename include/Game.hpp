
#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "Food.hpp" // this includes board and snake

#define WINDOW_SIZE 800
// this allows for connection between server and clients
class Game {
public:
    Game(Snake &player, Board &level, Food& point);
    ~Game();
    void run();
private:
    bool isRunning;
    Board &level;
    Snake &playerActor;
    Food &point;
    int points = 0;

    void close(sf::RenderWindow &window);
    void processInput(sf::RenderWindow &window);
};


#endif //SNAKE_GAME_HPP
