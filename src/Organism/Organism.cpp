/**
 * @class Organism
 * @file Organism.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */

#include "Organism.h"


bool Organism::isWeakerThan(const Organism* other) const {
	return this->t_strengthI < other->t_strengthI ||
		   (this->t_strengthI == other->t_strengthI && this->t_ageI < other->t_ageI);
}
bool Organism::isStrongerThan(const Organism* other) const {
	return this->t_strengthI > other->t_strengthI ||
		   (this->t_strengthI == other->t_strengthI && this->t_ageI > other->t_ageI);
}
