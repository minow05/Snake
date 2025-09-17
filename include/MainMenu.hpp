
#ifndef SNAKE_MAINMENU_HPP
#define SNAKE_MAINMENU_HPP

#include "Server.hpp"
#include "Session.hpp"
#include "Client.hpp"
#include <SFML/Graphics.hpp>

class Game;

class MainMenu {
private:
    sf::Font font;
    void run(Game &gameInstance);
public:
    explicit MainMenu(Game &gameInstance);
    void createHostUI(Server& host);
    void connectToHostUI(Client& client);

};


#endif //SNAKE_MAINMENU_HPP
