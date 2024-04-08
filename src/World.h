/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_WORLD_H
#define GAMEOFLIFEOOP_WORLD_H

#include "Organism/Organism.h"

#include <vector>


class World {
	int sizeI_;

	std::vector<std::unique_ptr<Organism>> organisms_;

	std::vector<std::vector<Organism*>> worldPlane_;

	static bool compareGraterInitiative(const std::unique_ptr<Organism>& a, const std::unique_ptr<Organism>& b);

public:
	explicit World(int size) : sizeI_(size) {
		worldPlane_.resize(size);
		for (auto& inner_vec: worldPlane_) {
			inner_vec.resize(size);
		}
	}

	void addOrganism(Organism* newOrganism);
	void addOrganism(Organism* newOrganism, int atX, int atY);

	void removeOrganism();

	void updateWorld();

	void drawWorld() const;

	/* Getters & Setters */

	[[nodiscard]] int getSize() const { return this->sizeI_; }
};


#endif // GAMEOFLIFEOOP_WORLD_H
