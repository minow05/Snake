cmake_minimum_required(VERSION 3.31)
project(Snake)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ASIO
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
        GIT_TAG asio-1-30-2  # change to latest stable if needed
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(ASIO)

add_executable(Snake
        src/main.cpp
        src/Snake.cpp
        include/Snake.hpp
        src/Game.cpp
        include/Game.hpp
        src/Board.cpp
        include/Board.hpp
        src/Food.cpp
        include/Food.hpp
        src/MainMenu.cpp
        include/MainMenu.hpp
        include/CellState.hpp
        src/Server.cpp
        include/Server.hpp
        src/Client.cpp
        include/Client.hpp
        src/Session.cpp
        include/Session.hpp)

target_link_libraries(Snake PRIVATE SFML::Graphics)

target_include_directories(Snake PRIVATE
        ${asio_SOURCE_DIR}/asio/include
)