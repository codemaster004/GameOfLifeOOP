/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_WORLD_H
#define GAMEOFLIFEOOP_WORLD_H

#include "Organism/Organism.h"

#include <vector>


class World {
	int t_sizeI;

	std::vector<std::unique_ptr<Organism>> t_organisms;

	std::vector<std::vector<Organism*>> t_worldPlane;

	Organism* getFromWorld(Vec2 position) {
		return t_worldPlane[static_cast<int>(position.y)][static_cast<int>(position.x)];
	}

	void moveInWorld(Vec2 initialPos, Vec2 destinationPos);

	static bool compareGraterInitiative(const std::unique_ptr<Organism>& iterE, const std::unique_ptr<Organism>& newE);

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
	[[nodiscard]] bool isOccupied(Vec2 pos) const;

	/* Getters & Setters */

	[[nodiscard]] int getSize() const { return this->t_sizeI; }
};


#endif // GAMEOFLIFEOOP_WORLD_H
