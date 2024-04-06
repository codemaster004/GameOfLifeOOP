/**
 * @class World
 * @file World.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */
#include "World.h"


bool World::compareGraterInitiative(const std::unique_ptr<Organism>& a, const std::unique_ptr<Organism>& b) {
	return a->getInitiative() > b->getInitiative() ||
		   (a->getInitiative() == b->getInitiative() && a->getAge() > b->getAge());
}

void World::addOrganism(Organism* newOrganism, int x, int y) {
	// Wrap the raw pointer in a std::unique_ptr before insertion
	std::unique_ptr<Organism> organismPtr(newOrganism);
	// Add the raw pointer to the world plane
	worldPlane_[y][x] = organismPtr.get();

	// Use std::lower_bound with the comparison function to find correct space in the vector
	auto iter = std::lower_bound(organisms_.begin(), organisms_.end(), organismPtr, compareGraterInitiative);
	// Insert the unique_ptr into the vector, transferring ownership
	organisms_.insert(iter, std::move(organismPtr));
}

void World::drawWorld() const {
	for (auto& worldRow: worldPlane_) {
		for (auto& org_p: worldRow) {
			std::cout << " "; // prettying the output

			// if there is no Organism at this spot
			if (org_p == nullptr) {
				std::cout << ".";
				continue;
			}

			// run the Organims draw function
			org_p->draw();
		}
		std::cout << std::endl; // prettying the output
	}
}
