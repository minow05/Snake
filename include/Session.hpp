
#ifndef SNAKE_SESSION_HPP
#define SNAKE_SESSION_HPP
#include "asio.hpp"


class Session : std::enable_shared_from_this<Session>{
private:
    asio::ip::tcp::resolver resolver;
    uint8_t packet;
    asio::ip::tcp::socket socket;
    void readPlayerInput();

public:
    void writeGameState(uint8_t gameState);
    explicit Session(asio::io_context& io);
    void start();
};


#endif //SNAKE_SESSION_HPP
