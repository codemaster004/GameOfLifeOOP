/**
 * @class Organism
 * @file Organism.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */

#include "Organism.h"

#include "../World.h"

#include <random>

#include "Animals/Antelope.h"
#include "Animals/Fox.h"
#include "Animals/Sheep.h"
#include "Animals/Turtle.h"
#include "Animals/Wolf.h"
#include "Human.h"
#include "Plants/Belladonna.h"
#include "Plants/Grass.h"
#include "Plants/Guarana.h"
#include "Plants/SosnowskysHogweed.h"
#include "Plants/SowThistle.h"


bool Organism::isWeakerThan(const Organism* other) const {
	return this->t_strengthI < other->t_strengthI ||
		   (this->t_strengthI == other->t_strengthI && this->t_ageI < other->t_ageI);
}
bool Organism::isStrongerThan(const Organism* other) const {
	return this->t_strengthI > other->t_strengthI ||
		   (this->t_strengthI == other->t_strengthI && this->t_ageI > other->t_ageI);
}
void Organism::moveTo(Vec2 destination) {
	t_enviromentWorld_p->moveInWorld(t_positionVec2, destination);
	t_positionVec2 = destination;
}
void Organism::removeFromWorld() const { t_enviromentWorld_p->removeFrom(t_positionVec2); }

int Organism::getRandom(int from, int to) {
	// Random number engine initialized with seed
	std::mt19937 engine{std::random_device{}()};
	// Uniform distribution from 1 to 100
	std::uniform_int_distribution dist(from, to);

	return dist(engine); // return random number from range
}

Organism* Organism::createOrganism(OrganismType type) {
	switch (type) {
		case OrganismType::Human:
			return new class Human();
		case OrganismType::Antelope:
			return new Antelope();
		case OrganismType::Fox:
			return new Fox();
		case OrganismType::Sheep:
			return new Sheep();
		case OrganismType::Turtle:
			return new Turtle();
		case OrganismType::Wolf:
			return new Wolf();
		case OrganismType::Belladonna:
			return new Belladonna();
		case OrganismType::Grass:
			return new Grass();
		case OrganismType::Guarana:
			return new Guarana();
		case OrganismType::SosnowskysHogweed:
			return new SosnowskysHogweed();
		case OrganismType::SowThistle:
			return new SowThistle();
		case OrganismType::Plant:
		case OrganismType::Animal:
			return nullptr;
	}
	return nullptr;
}
