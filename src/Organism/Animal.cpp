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


float Animal::envSizeBound(int newValue, int envSize) { return static_cast<float>(newValue % envSize); }

Vec2 Animal::generateNewRandomPosition(Vec2 currectPos, const World* enviroment_p) {
	int envSize = enviroment_p->getSize();
	Vec2 newPosition = {envSizeBound(static_cast<int>(currectPos.x) + static_cast<int>(random() % 2), envSize),
						envSizeBound(static_cast<int>(currectPos.y) + static_cast<int>(random() % 2), envSize)};
	return newPosition;
}

Vec2 Animal::step() { return generateNewRandomPosition(t_positionVec2, t_enviromentWorld_p); }
