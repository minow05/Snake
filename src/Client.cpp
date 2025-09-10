#include <iostream>
#include "../include/Client.hpp"

void Client::sendData(uint8_t packet) {
    auto self = shared_from_this();
    acceptor.async_accept([self, this](std::error_code ec, asio::ip::tcp::socket socket) {
        if (!ec) {
            auto session = std::make_shared<Session>(std::move(socket));
            self->sessions.push_back(session);
            session->start();
            std::cout << "Player connected\n";
        }
        self->accept();
    });
}

Client::Client(asio::io_context &io, const std::string &host, uint16_t port) : io(io),  {

}

void Client::start() {
    auto self = shared_from_this();
    resolver.async_resolve(host, std::to_string(port), [this, self](std::error_code ec, asio::ip::tcp::resolver::results_type results) {
       if (!ec){
           asio::async_connect(socket, results, [this, self](std::error_code ec, const asio::ip::tcp::endpoint& endpoint) {
               if (!ec){
                   std::cout << "Connected to server\n";
                   read();
               }
               else std::cout << "Failed to connect to server\n";
           });
       }
    });
}

void Client::read() {
    auto self = shared_from_this();
    socket.async_read_some(asio::buffer(buffer),[this, self](std::error_code ec, std::size_t length) {
        if (!ec) {
            std::cout << "Received: ";
            for (size_t i = 0; i < length; i++) {
                std::cout << int(buffer[i]) << " ";
            }
            std::cout << "\n";
            read();
        }
    });
}
