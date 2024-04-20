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


int Animal::envSizeBound(int newValue, int envSize) { return (envSize + newValue) % envSize; }

Vec2 Animal::generateRandomPosition(Vec2 currectPos, const World* enviroment_p, int range, bool canStay) {

	int newRandomY = getRandom(-1 * range, 1 * range);
	int newRandomX = getRandom(-1 * range, 1 * range);
	// (!(newRandomX == 0 ^ newRandomY == 0))
	while (!canStay && newRandomX == 0 && newRandomY == 0 ||
		   Vec2::length({0, 0}, {newRandomX, newRandomY}) > static_cast<float>(range)) {
		newRandomX = getRandom(-1 * range, 1 * range);
		newRandomY = getRandom(-1 * range, 1 * range);
	}

	int envSize = enviroment_p->getSize();
	Vec2 newPosition = {envSizeBound(currectPos.x + newRandomX, envSize),
						envSizeBound(currectPos.y + newRandomY, envSize)};
	return newPosition;
}

Vec2 Animal::step() { return generateRandomPosition(t_positionVec2, t_enviromentWorld_p, t_movementSpeedI); }

void Animal::collision(Organism* attacker, CollisionContext& context) { context.resolveByFighting(this, attacker); }
