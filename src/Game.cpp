
#include <iostream>
#include "../include/Game.hpp"

Game::Game(Snake &player, Board &level, Food &point) : playerActor(player), level(level), point(point) {}

void Game::processInput(sf::RenderWindow &window) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            this->close(window);
            break;
        }
        auto keyEvent = event->getIf<sf::Event::KeyPressed>();
        if (keyEvent != nullptr){
            if (keyEvent->code == sf::Keyboard::Key::Up) playerActor.setDirection(Snake::Direction::up);
            else if (keyEvent->code == sf::Keyboard::Key::Down) playerActor.setDirection(Snake::Direction::down);
            else if (keyEvent->code == sf::Keyboard::Key::Left) playerActor.setDirection(Snake::Direction::left);
            else if (keyEvent->code == sf::Keyboard::Key::Right) playerActor.setDirection(Snake::Direction::right);
        }
    }
}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Snake Game");

    sf::View cartesianView;

    cartesianView.setCenter({WINDOW_SIZE/2, WINDOW_SIZE/2});
    cartesianView.setSize({WINDOW_SIZE, -WINDOW_SIZE});

    window.setView(cartesianView);

    window.setFramerateLimit(3);

    while (this->isRunning) {
        //handle input
        this->processInput(window);

        //handle logic
        if (playerActor.checkIfTouch()){
            this->close(window);
            break;
        }
        if (point.tryCollect(playerActor, level)){
            point = Food(level);
            points++;
        }
        playerActor.move(level);

        //render
        window.clear(sf::Color::White);
        level.render(window);

        window.display();
    }
}

Game::~Game() {
    std::cout << "You have scored " << points << " points!\n";
    delete &playerActor;
    delete &level;
    delete &point;
}

void Game::close(sf::RenderWindow &window) {
    isRunning = false;
    window.close();
//    delete this; WHY DOES IT INDUCE STATUS_HEAP_CORRUPTION???
}
