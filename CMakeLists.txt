cmake_minimum_required(VERSION 3.27)
project(GameOfLifeOOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLifeOOP main.cpp
        src/Organism/Human.cpp
        src/Organism/Human.h
        src/Organism/Organism.cpp
        src/Organism/Organism.h
        src/World.cpp
        src/World.h
        src/Utility/Vec2.h
        src/Utility/Vec2.cpp)
