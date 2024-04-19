/**
 * @file Plant.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 19/04/2024
 */
#include "Plant.h"

#include <set>

#include "../World.h"


Vec2 Plant::sow() {
	std::set<Vec2> emptyNeighbouringSpots;
	t_enviromentWorld_p->getAvailableSpotsAround(emptyNeighbouringSpots, t_positionVec2);
	if (!emptyNeighbouringSpots.empty()) {
		// t_enviromentWorld_p->addOrganism()
	}
}

Vec2 Plant::step() {
	int randomChance = getRandom(1, 100);
	if (randomChance <= t_sowChancePrecent) {
		sow();
	}
	return {-1, -1};
}
