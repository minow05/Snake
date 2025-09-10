
#ifndef SNAKE_CLIENT_HPP
#define SNAKE_CLIENT_HPP

#include "asio.hpp"

//this(Snake) sends movement input to Server (Board)

class Client : std::enable_shared_from_this<Client> {
public:
    Client(asio::io_context& io, const std::string& host, uint16_t port);
    void start();
    void sendData(uint8_t packet);
private:
    asio::io_context& io;
    asio::ip::tcp::resolver resolver;
    asio::ip::tcp::socket socket;
    std::string host;
    uint16_t port;
    std::array<uint8_t, 128> buffer{};
    void read();
};


#endif //SNAKE_CLIENT_HPP
