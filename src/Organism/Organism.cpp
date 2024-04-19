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
