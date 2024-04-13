/**
 * @file Fox.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 12/04/2024
 */
#include "Fox.h"
#include "../../World.h"

#include <set>


Vec2 Fox::step() {
	// start by generating random move as for ordinary animal
	// if the picked spot is unocupied or occupied by a weaker animal return randomSpot
	if (Vec2 randomSpot = generateRandomPosition(t_positionVec2, t_enviromentWorld_p, t_movementSpeedI);
		!t_enviromentWorld_p->isOccupied(randomSpot) ||
		t_enviromentWorld_p->getFromWorld(randomSpot)->getStrength() < t_strengthI) {
		return randomSpot;
	}

	// in case the spot is ocupied by a stronger animal try picking a different one

	// get all available positions around the fox
	std::set<Vec2> availablePositions;
	t_enviromentWorld_p->getAvailableSpotsAround(availablePositions, t_positionVec2, t_strengthI);

	// return any +- random position
	if (!availablePositions.empty()) {
		auto it = availablePositions.begin();
		return *it;
	}
	// or if there are none stay in the same spot
	return {-1, -1};
}
