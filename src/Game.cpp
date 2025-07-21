
#include <iostream>
#include "../include/Game.hpp"

Game::Game(Snake &player, Board &level, Food &point) : playerActor(player), level(level), point(point) {}

void Game::processInput(sf::RenderWindow &window) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
            std::cout << "You scored " << points << " points!\n";
        }
        auto keyEvent = event->getIf<sf::Event::KeyPressed>();
        if (keyEvent != nullptr){
            if (keyEvent->code == sf::Keyboard::Key::Up) playerActor.setDirection(Snake::Direction::down);
            else if (keyEvent->code == sf::Keyboard::Key::Down) playerActor.setDirection(Snake::Direction::up);
            else if (keyEvent->code == sf::Keyboard::Key::Left) playerActor.setDirection(Snake::Direction::left);
            else if (keyEvent->code == sf::Keyboard::Key::Right) playerActor.setDirection(Snake::Direction::right);
        }
    }
}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Snake Game");

    window.setFramerateLimit(3);

    while (window.isOpen()) {
        //handle input
        this->processInput(window);


        //handle logic

        if (point.tryCollect(playerActor)){
            point = Food({rand() % level.boardSize, rand() % level.boardSize});
            points++;
        }
        playerActor.move(level);

        //render
        window.clear(sf::Color::White);
        level.render(window);
        point.render(window, level);
        playerActor.render(window, level);

        window.display();
    }
}
