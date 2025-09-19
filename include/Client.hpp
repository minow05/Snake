
#ifndef SNAKE_CLIENT_HPP
#define SNAKE_CLIENT_HPP

#include "asio.hpp"
#include "CellState.hpp"

//this(Snake) sends movement input to Server (Board)

class Client : std::enable_shared_from_this<Client> {
public:
    Client();
    void start();
    void sendData(uint8_t data);
    void setHost(std::string h);
    void setPort(uint16_t p);
private:
    asio::io_context io;
    asio::ip::tcp::resolver resolver;
    asio::ip::tcp::socket socket;
    std::string host;
    uint16_t port;
    std::vector<std::vector<CellState>> buffer;
    void handlePacket(uint8_t p);
    void read();
};


#endif //SNAKE_CLIENT_HPP
