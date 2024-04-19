/**
 * @file SosnowskysHogweed.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 19/04/2024
 */
#include "SosnowskysHogweed.h"

#include "../../World.h"

Vec2 SosnowskysHogweed::step() {
	std::set<Vec2> occupiedCells; // get heighbouring cells with organisms
	t_enviromentWorld_p->getOccupiedSpotsAround(occupiedCells, t_positionVec2);

	for (const Vec2& neighbourPos: occupiedCells) {
		Organism* neighbour = t_enviromentWorld_p->getFromWorld(neighbourPos);
		// Hogweed kills every animal next to it
		neighbour->unalive();
		t_enviromentWorld_p->removeFrom(neighbourPos);
	}
	return {-1, -1};
}
