
#include <iostream>
#include "../include/Server.hpp"

Server::Server(int playerLim) : playerNumberLimit(playerLim), acceptor(io) {
    io.run();
}

void Server::accept() {
    auto self = shared_from_this();
    acceptor.async_accept([self, this](std::error_code ec, asio::ip::tcp::socket socket) {
        if (!ec) {
//            auto session = std::make_shared<Session>(std::move(socket));
//            self->sessions.push_back(session);
//            session->start();
            std::cout << "Player connected\n";
        }
        self->accept();
    });
}

void Server::setPort(uint16_t p) {
    acceptor.bind(asio::ip::tcp::endpoint(asio::ip::tcp::v4(), p));
    accept();
}
