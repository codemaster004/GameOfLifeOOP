/**
 * @class World
 * @file World.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */
#include "World.h"


bool World::compareGraterInitiative(const OrganismInfo& iterE, const std::unique_ptr<Organism>& newE) {
	return iterE.organism_p->getInitiative() > newE->getInitiative() ||
		   (iterE.organism_p->getInitiative() == newE->getInitiative() && iterE.organism_p->getAge() > newE->getAge());
}

void World::addOrganism(Organism* newOrganism) {
	// Set Enviroment as this Word
	newOrganism->setEnviroment(this);

	// Wrap the raw pointer in a std::unique_ptr before insertion
	std::unique_ptr<Organism> organismPtr(newOrganism);
	// Add the raw pointer to the world plane
	t_worldPlane[newOrganism->getY()][newOrganism->getX()] = organismPtr.get();

	// Use std::lower_bound with the comparison function to find correct space in the vector
	auto iter = std::lower_bound(t_organisms.begin(), t_organisms.end(), organismPtr, compareGraterInitiative);
	// Insert the unique_ptr into the vector, transferring ownership
	t_organisms.insert(iter, {std::move(organismPtr), {0, 0}});
}

void World::addOrganism(Organism* newOrganism, int atX, int atY) {
	if (atX >= t_sizeI || atY >= t_sizeI) {
		// todo: throw
	}
	newOrganism->setPosition(atX, atY);
	addOrganism(newOrganism);
}

void World::updateWorld() {
	for (auto organism_p = t_organisms.begin(); organism_p != t_organisms.end();) {
		if (!organism_p->organism_p->isAlive()) {
			// at this stage raw pointer in worldPlane sould already be removed
			// todo: check & throw

			// Remove the Organism from the vector, and keep the loop in place
			organism_p = t_organisms.erase(organism_p);
		} else {
			organism_p->organism_p->step(); // run the action for the organism
			++organism_p; // move to the next Organism
		}
	}
}

void World::drawWorld() const {
	for (auto& worldRow: t_worldPlane) {
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

bool World::isOccupied(int x, int y) const { return t_worldPlane[y][x] != nullptr; }
