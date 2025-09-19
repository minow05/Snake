
#include <iostream>
#include "../include/Session.hpp"

void Session::readPlayerInput() {
    auto self = shared_from_this();
    asio::async_read(socket, asio::buffer(&packet, 1), [self](std::error_code ec, std::size_t packet) {
        if (!ec) {
            std::cout << "Received: " << packet << "\n";
            self->handlePacket(packet);
            self->readPlayerInput();
        } else {
            std::cerr << "Read error: " << ec.message() << "\n";
        }
    });
}

void Session::writeGameState(uint8_t gameState) {
    auto self = shared_from_this();
    asio::async_write(socket, asio::buffer(&gameState, sizeof(gameState)), [this, self, &gameState](std::error_code ec, std::size_t length) {
        if (!ec) {
            std::cout << "Sent " << gameState << " bytes\n";
        }
    });
}

Session::Session(asio::io_context& io) : resolver(io), socket(io){

}

void Session::start() {
    readPlayerInput();
}

void Session::handlePacket(uint8_t p) {

}
