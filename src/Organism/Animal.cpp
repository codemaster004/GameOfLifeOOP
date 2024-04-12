/**
 * @class Animal
 * @file Animal.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 08/04/2024
 */
#include "Animal.h"
#include "../World.h"

#include <random>


float Animal::envSizeBound(int newValue, int envSize) { return static_cast<float>(newValue % envSize); }

Vec2 Animal::generateNewRandomPosition(Vec2 currectPos, const World* enviroment_p) {
	// Random number engine initialized with seed
	std::mt19937 engine{std::random_device{}()};

	// Uniform distribution from 1 to 100
	std::uniform_int_distribution dist(-1, 1);
	int newRandomY = 0;
	int newRandomX = 0;
	while (newRandomX == 0 && newRandomY == 0) {
		newRandomX = dist(engine);
		newRandomY = dist(engine);
	}

	int envSize = enviroment_p->getSize();
	Vec2 newPosition = {envSizeBound(static_cast<int>(currectPos.x) + newRandomX, envSize),
						envSizeBound(static_cast<int>(currectPos.y) + newRandomY, envSize)};
	return newPosition;
}

Vec2 Animal::step() { return generateNewRandomPosition(t_positionVec2, t_enviromentWorld_p); }
