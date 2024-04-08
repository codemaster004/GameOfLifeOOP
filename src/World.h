/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_WORLD_H
#define GAMEOFLIFEOOP_WORLD_H

#include "Organism/Organism.h"

#include <vector>


class World {
	int t_sizeI;

	struct OrganismInfo {
		std::unique_ptr<Organism> organism_p;
		Vec2 moveVec2;
	};

	std::vector<OrganismInfo> t_organisms;

	std::vector<std::vector<Organism*>> t_worldPlane;

	static bool compareGraterInitiative(const OrganismInfo& iterE, const std::unique_ptr<Organism>& newE);

public:
	explicit World(int size) : t_sizeI(size) {
		t_worldPlane.resize(size);
		for (auto& innerVec: t_worldPlane) {
			innerVec.resize(size);
		}
	}

	void addOrganism(Organism* newOrganism);
	void addOrganism(Organism* newOrganism, int atX, int atY);

	void updateWorld();

	void drawWorld() const;

	[[nodiscard]] bool isOccupied(int x, int y) const;

	/* Getters & Setters */

	[[nodiscard]] int getSize() const { return this->t_sizeI; }
};


#endif // GAMEOFLIFEOOP_WORLD_H
