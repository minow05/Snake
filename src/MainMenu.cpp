
#include <iostream>
#include "../include/MainMenu.hpp"
#include "../include/Game.hpp"

MainMenu::MainMenu(Game &gameInstance){
    if (!font.openFromFile("../assets/Pixeled.ttf")){
        std::cout << "Failed to load font" << std::endl;
    }
    this->run(gameInstance);
}


void MainMenu::run(Game &gameInstance) {
    sf::RenderWindow window(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Menu");
    std::vector<std::string> items = {"SINGLE_PLAYER", "HOST_GAME", "JOIN_GAME", "EXIT"};
    int selectedIndex = 0;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                break;
            }
            auto keyEvent = event->getIf<sf::Event::KeyPressed>();
            if (keyEvent != nullptr){
                if (keyEvent->code == sf::Keyboard::Key::Up) selectedIndex = (selectedIndex - 1) % items.size();
                else if (keyEvent->code == sf::Keyboard::Key::Down) selectedIndex = (selectedIndex + 1) % items.size();
                else if (keyEvent->code == sf::Keyboard::Key::Enter) {
                    switch (selectedIndex) {
                        case 0:
                            gameInstance.runSinglePlayer();
                            break;
                        case 1:
                            gameInstance.runHost();
                            break;
                        case 2:
                            gameInstance.runClient();
                            break;
                        case 3:
                            window.close();
                            break;
                    }
                }
            }
        }
        window.clear(sf::Color::Black);
        for (int i = 0; i < items.size(); i++) {
            sf::Text text(font, items[i], WINDOW_SIZE/40);
            i == selectedIndex ? text.setFillColor(sf::Color::Red) : text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(WINDOW_SIZE/4, WINDOW_SIZE/8 + i * WINDOW_SIZE/20));
            window.draw(text);
        }
        window.display();
    }
}

void MainMenu::connectToHostUI(Client &client) {
    //TODO: finish this
}

void MainMenu::createHostUI(Server& host){
    //TODO: finish this
}

