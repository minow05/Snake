
#ifndef SNAKE_SERVER_HPP
#define SNAKE_SERVER_HPP

#include "asio.hpp"
#include "Session.hpp"

//hosts Board, checks if Food is collected
class Server : std::enable_shared_from_this<Server> {
private:
    uint16_t port;
    asio::io_context io;
    asio::ip::tcp::acceptor acceptor;
    void accept();
    std::vector<std::weak_ptr<Session>> sessions;
    int playerNumberLimit = 0;
public:
    Server(int playerLim);
    void setPort(uint16_t p);
};


#endif //SNAKE_SERVER_HPP
