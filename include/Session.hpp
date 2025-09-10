
#ifndef SNAKE_SESSION_HPP
#define SNAKE_SESSION_HPP
#include "asio.hpp"


class Session : std::enable_shared_from_this<Session>{
private:
    asio::ip::tcp::resolver resolver;
    std::list<uint16_t> listOfPorts;
    asio::ip::tcp::socket socket;
    void readPlayerInput();
    void writeGameState();

public:
    explicit Session(asio::ip::tcp::socket socket);
    void start();
};


#endif //SNAKE_SESSION_HPP
