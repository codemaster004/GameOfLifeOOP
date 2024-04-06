cmake_minimum_required(VERSION 3.27)
project(GameOfLifeOOP)

set(CMAKE_CXX_STANDARD 17)

# Library paths
set(LIB_DS_PATH /Users/filip/Developer/Cpp/DataStructs)

# Data Structures Library
include_directories(${LIB_DS_PATH}/include)
link_directories(${LIB_DS_PATH}/lib)

add_executable(GameOfLifeOOP main.cpp
        src/Organism/Human.cpp
        src/Organism/Human.h
        src/Organism/Organism.cpp
        src/Organism/Organism.h
        src/World.cpp
        src/World.h
        src/Utility/Vec2.h
        src/Utility/Vec2.cpp
        src/Organism/Plants/Grass.cpp
        src/Organism/Plants/Grass.h
        src/Organism/Plant.cpp
        src/Organism/Plant.h)

target_link_libraries(GameOfLifeOOP PRIVATE DataStructs)
