
#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include "Food.hpp" // this includes board and snake
#include "asio.hpp"
#include "MainMenu.hpp"

#define WINDOW_SIZE 800
// this allows for connection between server and clients

class Game {
public:
    Game(Snake &player, Board &level, Food& point);
    ~Game();
    void runSinglePlayer();
    void runClient();
    void runHost();
private:

    Board &level;
    Snake &playerActor;
    Food &point;
    MainMenu menu;
    int points = 0;
    bool isRunning;



    sf::RenderWindow createWindow();
    void close(sf::RenderWindow &window);
    void processInput(sf::RenderWindow &window);
    void handleLogic(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
};


#endif //SNAKE_GAME_HPP
