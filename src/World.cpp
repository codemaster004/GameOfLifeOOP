/**
 * @class World
 * @file World.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */
#include "World.h"
#include "Organism/CollisionContext.h"

#include <fstream>
#include <list>


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
void World::iterateOverNeighbours(Vec2 pos, const std::function<void(Vec2)>& callback) const {
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
		return;
	}
	if (t_worldPlane[atY][atX] != nullptr) {
		return;
	}

	newOrganism->setPosition(atX, atY);
	addOrganism(newOrganism);
}

void World::queueOrganismBirth(Organism* newOrganism, int atX, int atY) {
	t_queuedBirth.push_back({newOrganism, atX, atY});
}

void World::updateWorld() {
	std::list<CollisionContext> collisionsInfo;

	for (auto organism_it = t_organisms.begin(); organism_it != t_organisms.end();) {
		if (!(*organism_it)->isAlive()) {
			// at this stage raw pointer in worldPlane sould already be removed
			// todo: check & throw

			// Remove the Organism from the vector, and keep the loop in place
			t_organisms.erase(organism_it);
		} else {
			(*organism_it)->updateBreedColldown();
			Vec2 moveTo = (*organism_it)->step(); // generate new possition for organisms

			if (moveTo.x < 0 || moveTo.y < 0) {
				++organism_it; // skip this Organism
				continue;
			}

			if (isOccupied(moveTo)) {
				// create a information about collision happening and resolve it
				CollisionContext context((*organism_it)->getStrength(), (*organism_it)->getPossition(), moveTo, this);
				getFromWorld(moveTo)->collision(organism_it->get(), context);
				collisionsInfo.push_back(context);
			} else {
				moveInWorld((*organism_it)->getPossition(), moveTo);
				(*organism_it)->setPosition(moveTo);
			}
#ifdef DEBUG
			drawWorld();
#endif // DEBUG

			++organism_it; // move to the next Organism
		}
	}
	for (auto& info: collisionsInfo) {
		info.log();
	}

	for (auto& [organism_p, x, y]: t_queuedBirth) {
		addOrganism(organism_p, x, y);
	}
	t_queuedBirth.clear();
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

void World::getAvailableSpotsAround(std::set<Vec2>& buffor, Vec2 position, int strengthLimit) const {
	iterateOverNeighbours(position, [&buffor, strengthLimit, this](Vec2 checkPos) {
		// always accept spots that are unoccupied
		if (!isOccupied(checkPos) || // or if strengthLimit is defined spots where animal has less strength
			strengthLimit != 0 && getFromWorld(checkPos)->getStrength() < strengthLimit) {

			buffor.insert(checkPos);
		}
	});
}

void World::getOccupiedSpotsAround(std::set<Vec2>& buffor, Vec2 position) const {
	iterateOverNeighbours(position, [&buffor, this](Vec2 checkPos) {
		if (this->getFromWorld(checkPos) != nullptr) {
			buffor.insert(checkPos);
		}
	});
}

void World::addToBirthQueue(const OrganismInfo info) { t_queuedBirth.push_back(info); }

void World::saveGamaState() const {
	std::ofstream outFile("save.txt");
	if (outFile.is_open()) {
		outFile << t_organisms.size() << std::endl; // write vector size to file
		// write all organisms to file
		for (auto& organism: t_organisms) {
			organism->serialize(outFile);
		}
		outFile.close();
	}
}

void World::loadGameState() {
	std::ifstream inFile("save.txt");
	if (inFile.is_open()) {
		// Input number of organisms present in a file
		int nOrganism;
		inFile >> nOrganism;
		inFile.ignore();

		for (int i = 0; i < nOrganism; ++i) {
			int type; // load organism type
			inFile >> type;
			inFile.ignore();

			// try creating new organism of given type
			Organism* organism = Organism::createOrganism(static_cast<Organism::OrganismType>(type));
			if (organism) {
				organism->deserialize(inFile);
				addOrganism(organism);
			}
		}

		inFile.close();
	}
}
