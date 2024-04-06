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

void World::addOrganism(Organism* newOrganism) {
	// Wrap the raw pointer in a std::unique_ptr before insertion
	std::unique_ptr<Organism> organismPtr(newOrganism);

	// Use std::lower_bound with the comparison function to find correct space in the vector
	auto iter = std::lower_bound(organisms_.begin(), organisms_.end(), organismPtr, compareGraterInitiative);
	// Insert the unique_ptr into the vector, transferring ownership
	organisms_.insert(iter, std::move(organismPtr));
}
