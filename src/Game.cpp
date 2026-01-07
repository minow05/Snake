
#include <iostream>
#include "../include/Game.hpp"

Game::Game(Snake player, Board level, Food point) : playerActor(std::move(player)), level(std::move(level)), point(std::move(point)), menu(*this) {

}

Game::Game() : menu(*this) {}

Game::~Game() {
    std::cout << "You have scored " << points << " points!\n";
//    delete &playerActor;
//    delete &level;
//    delete &point;
}

void Game::close(sf::RenderWindow &window) {
    isRunning = false;
    window.close();
}

void Game::runSinglePlayer() {
    menu.createSinglePlayer(*this);
    buildLevel(15);
    buildActor();
    buildPoint(level);
    auto window = this->createWindow();
    this->isRunning = true;
    this->points = 0;
    while (this->isRunning) {
        this->processInput(window);
        this->handleLogic(window);
        this->render(window);
    }
}

void Game::runClient() {
    Client client;
    menu.connectToHostUI(client);
    //TODO: finish this
}

void Game::runHost() {
    Server server(2);
    menu.createHostUI(server);
    //TODO: finish this
}

sf::RenderWindow Game::createWindow() {
    sf::RenderWindow window(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Snake Game");

    sf::View cartesianView;

    cartesianView.setCenter({WINDOW_SIZE/2, WINDOW_SIZE/2});
    cartesianView.setSize({WINDOW_SIZE, -WINDOW_SIZE});

    window.setView(cartesianView);

    window.setFramerateLimit(8);

    return window;
}

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

void Game::handleLogic(sf::RenderWindow &window) {

    if (playerActor.checkIfTouch()){
        this->close(window);
    }
    if (point.tryCollect(playerActor, level)){ //Board.food.checkIf()
        point = Food(level);
        points++;
    }
    level.snakeMove(playerActor); //Board.snake.move()
}

void Game::render(sf::RenderWindow &window) {
    window.clear(sf::Color::White);
    level.render(window);

    window.display();
}

void Game::buildLevel(int boardSize) {
    level = Board(WINDOW_SIZE, boardSize);
}

void Game::buildActor() {
//    level.players.push_back(this->playerActor);
    level.snakeEmplace(playerActor, sf::Vector2i(level.boardSize/2, level.boardSize/2));
}

void Game::buildPoint(Board& board) {
    point = Food(board);
//    level.point.push_back(&point);
}




