/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_WORLD_H
#define GAMEOFLIFEOOP_WORLD_H

#include "Organism/Organism.h"

#include <vector>


class World {
	std::vector<std::unique_ptr<Organism>> organisms_;

	static bool compareGraterInitiative(const std::unique_ptr<Organism>& a, const std::unique_ptr<Organism>& b);

public:
	void addOrganism(Organism* newOrganism);

	void removeOrganism();

	void updateWorld();

	void drawWorld();
};


#endif //GAMEOFLIFEOOP_WORLD_H
