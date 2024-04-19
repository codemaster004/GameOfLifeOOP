/**
 * @class World
 * @file World.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */
#include "World.h"

#include <list>

#include "Organism/CollisionContext.h"


void World::moveInWorld(Vec2 initialPos, Vec2 destinationPos) {
	if (!isValidPosition(destinationPos)) {
		return;
	}

	int fromY = initialPos.y, fromX = initialPos.x;
	int toY = destinationPos.y, toX = destinationPos.x;
	t_worldPlane[toY][toX] = t_worldPlane[fromY][fromX];
	t_worldPlane[fromY][fromX] = nullptr;
}

void World::removeFrom(Vec2 position) { t_worldPlane[position.y][position.x] = nullptr; }

bool World::compareGraterInitiative(const std::unique_ptr<Organism>& iterE, const std::unique_ptr<Organism>& newE) {
	return iterE->getInitiative() > newE->getInitiative() ||
		   (iterE->getInitiative() == newE->getInitiative() && iterE->getAge() > newE->getAge());
}
void World::iterateOverNeighbours(Vec2 pos, const std::function<void(Vec2)>& callback) {
	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			// do not check moving 0 in both directions
			if (i == 0 && j == 0 || // or outside the movement range
				Vec2::length({0, 0}, {i, j}) > 1) {
				continue;
			}

			Vec2 checkPos = pos + Vec2{i, j};
			// only accept positions that fit inside the world borders
			if (!isInWorldBound(checkPos.x) || !isInWorldBound(checkPos.y)) {
				continue;
			}

			callback(checkPos);
		}
	}
}

void World::addOrganism(Organism* newOrganism) {
	// Set Enviroment as this World
	newOrganism->setEnviroment(this);

	// Wrap the raw pointer in a std::unique_ptr before insertion
	std::unique_ptr<Organism> organismPtr(newOrganism);
	// Add the raw pointer to the world plane
	t_worldPlane[newOrganism->getY()][newOrganism->getX()] = organismPtr.get();

	// Use std::lower_bound with the comparison function to find correct space in the vector
	auto iter = std::lower_bound(t_organisms.begin(), t_organisms.end(), organismPtr, compareGraterInitiative);
	// Insert the unique_ptr into the vector, transferring ownership
	t_organisms.insert(iter, std::move(organismPtr));
}

void World::addOrganism(Organism* newOrganism, int atX, int atY) {
	if (atX >= t_sizeI || atY >= t_sizeI) {
		// todo: throw
	}
	newOrganism->setPosition(atX, atY);
	addOrganism(newOrganism);
}

void World::updateWorld() {
	std::list<CollisionContext> collisionsInfo;

	for (auto organism_p = t_organisms.begin(); organism_p != t_organisms.end();) {
		if (!(*organism_p)->isAlive()) {
			// at this stage raw pointer in worldPlane sould already be removed
			// todo: check & throw

			// Remove the Organism from the vector, and keep the loop in place
			organism_p = t_organisms.erase(organism_p);
		} else {
			Vec2 moveTo = (*organism_p)->step(); // generate new possition for organisms

			if (moveTo.x < 0 || moveTo.y < 0) {
				++organism_p; // skip this Organism
				continue;
			}

			if (isOccupied(moveTo)) {
				// create a information about collision happening and resolve it
				CollisionContext context((*organism_p)->getStrength(), (*organism_p)->getPossition(), moveTo, this);
				getFromWorld(moveTo)->collision(organism_p->get(), context);
				collisionsInfo.push_back(context);
			} else {
				moveInWorld((*organism_p)->getPossition(), moveTo);
				(*organism_p)->setPosition(moveTo);
			}
#ifdef DEBUG
			drawWorld();
#endif // DEBUG

			++organism_p; // move to the next Organism
		}
	}
	for (auto& info: collisionsInfo) {
		info.log();
	}
}

void World::drawWorld() const {
	std::cout << "\033[2J\033[H"; // Clear the screen and move the cursor to the home position

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
bool World::isOccupied(Vec2 pos) const { return isOccupied(pos.x, pos.y); }

void World::getAvailableSpotsAround(std::set<Vec2>& buffor, Vec2 position, int strengthLimit) {
	iterateOverNeighbours(position, [&buffor, strengthLimit, this](Vec2 checkPos) {
		// always accept spots that are unoccupied
		if (!isOccupied(checkPos) || // or if strengthLimit is defined spots where animal has less strength
			strengthLimit != 0 && getFromWorld(checkPos)->getStrength() < strengthLimit) {

			buffor.insert(checkPos);
		}
	});
}
void World::getOccupiedSpotsAround(std::set<Vec2>& buffor, Vec2 position) {
	iterateOverNeighbours(position, [&buffor, this](Vec2 checkPos) {
		if (this->getFromWorld(checkPos) != nullptr) {
			buffor.insert(checkPos);
		}
	});
}
