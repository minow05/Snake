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
        include/CellState.hpp)

target_link_libraries(Snake PRIVATE SFML::Graphics)
