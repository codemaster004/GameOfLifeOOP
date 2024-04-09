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
        src/Organism/Plant.h
        src/Organism/Plants/SowThistle.cpp
        src/Organism/Plants/SowThistle.h
        src/Organism/Plants/Guarana.cpp
        src/Organism/Plants/Guarana.h
        src/Organism/Plants/Belladonna.cpp
        src/Organism/Plants/Belladonna.h
        src/Organism/Plants/SosnowskysHogweed.cpp
        src/Organism/Plants/SosnowskysHogweed.h
        src/Organism/Animals/Wolf.cpp
        src/Organism/Animals/Wolf.h
        src/Organism/Animals/Sheep.cpp
        src/Organism/Animals/Sheep.h
        src/Organism/Animals/Fox.cpp
        src/Organism/Animals/Fox.h
        src/Organism/Animals/Turtle.cpp
        src/Organism/Animals/Turtle.h
        src/Organism/Animals/Antelope.cpp
        src/Organism/Animals/Antelope.h
        src/Organism/Animal.cpp
        src/Organism/Animal.h
        src/Organism/CollisionContext.cpp
        src/Organism/CollisionContext.h
        src/Utility/Core.h
)

target_link_libraries(GameOfLifeOOP PRIVATE DataStructs)
