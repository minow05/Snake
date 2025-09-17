#include <iostream>
#include <utility>
#include "../include/Client.hpp"

void Client::sendData(uint8_t data) {
    auto self = shared_from_this();
    asio::async_write(socket, asio::buffer(&data, sizeof(data)), [this, self, &data](std::error_code ec, std::size_t length) {
        if (!ec) {
            std::cout << "Sent " << data << " bytes\n";
        }
    });
}

Client::Client() : socket(io), resolver(io) {
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
    io.run();
}

void Client::read() {
    auto self = shared_from_this();
    asio::async_read(socket, asio::buffer(&packet, 1), [self](std::error_code ec, std::size_t packet) {
        if (!ec) {
            std::cout << "Received: " << packet << "\n";
            self->read();
        } else {
            std::cerr << "Read error: " << ec.message() << "\n";
        }
    });
}

void Client::setHost(std::string h) {
    host = h;
}

void Client::setPort(uint16_t p) {
    port = p;
}

