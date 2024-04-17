/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_WORLD_H
#define GAMEOFLIFEOOP_WORLD_H

#include "Organism/Organism.h"

#include <set>
#include <vector>


class World {
	int t_sizeI;

	std::vector<std::unique_ptr<Organism>> t_organisms;

	std::vector<std::vector<Organism*>> t_worldPlane;

	static bool compareGraterInitiative(const std::unique_ptr<Organism>& iterE, const std::unique_ptr<Organism>& newE);

	[[nodiscard]] bool isInWorldBound(int value) const { return value >= 0 && value < t_sizeI; }
	[[nodiscard]] bool isValidPosition(Vec2 pos) const {
		return pos.x >= 0 && pos.y >= 0 && pos.x < t_sizeI && pos.y < t_sizeI;
	}

public:
	explicit World(int size) : t_sizeI(size) {
		t_worldPlane.resize(size);
		for (auto& innerVec: t_worldPlane) {
			innerVec.resize(size);
		}
	}

	void addOrganism(Organism* newOrganism);
	void addOrganism(Organism* newOrganism, int atX, int atY);

	void moveInWorld(Vec2 initialPos, Vec2 destinationPos);
	void removeFrom(Vec2 position);

	void updateWorld();

	void drawWorld() const;

	[[nodiscard]] bool isOccupied(int x, int y) const;
	[[nodiscard]] bool isOccupied(Vec2 pos) const;

	/* Getters & Setters */

	[[nodiscard]] Organism* getFromWorld(Vec2 position) const { return t_worldPlane[position.y][position.x]; }

	void getAvailableSpotsAround(std::set<Vec2>& buffor, Vec2 position, int strengthLimit = 0);

	[[nodiscard]] int getSize() const { return this->t_sizeI; }
};


#endif // GAMEOFLIFEOOP_WORLD_H
