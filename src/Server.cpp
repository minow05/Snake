
#include <iostream>
#include "../include/Server.hpp"

Server::Server(uint16_t port, int playerLim) : acceptor(io, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), playerNumberLimit(playerLim) {
    io.run();
}

void Server::accept() {
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