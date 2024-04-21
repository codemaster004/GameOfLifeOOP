/**
 * @file Plant.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 19/04/2024
 */
#include "Plant.h"
#include "../World.h"

#include <fstream>
#include <set>


void Plant::sow() {
	std::set<Vec2> emptyNeighbouringSpots;
	t_enviromentWorld_p->getAvailableSpotsAround(emptyNeighbouringSpots, t_positionVec2);
	if (!emptyNeighbouringSpots.empty()) {
		auto [x, y] = *emptyNeighbouringSpots.begin();

		t_enviromentWorld_p->queueOrganismBirth(this->getNewInstance(), x, y);
	}
}

Vec2 Plant::step() {
	int randomChance = getRandom(1, 100);
	if (randomChance <= t_sowChancePrecenI) {
		sow();
	}
	return {-1, -1};
}

void Plant::serialize(std::ofstream& outFile) const {
	outFile << t_sowChancePrecenI << ' ' << t_strengthI << ' ' << t_initiativeI << ' ' << t_ageI << ' ' << t_aliveBCond
			<< ' ' << t_breedCooldownI << ' ' << t_symbolC << ' ' << t_positionVec2.x << ' ' << t_positionVec2.y
			<< std::endl;
}

void Plant::deserialize(std::ifstream& inFile) {
	inFile >> t_sowChancePrecenI;
	inFile.ignore();
	inFile >> t_strengthI;
	inFile.ignore();
	inFile >> t_initiativeI;
	inFile.ignore();
	inFile >> t_ageI;
	inFile.ignore();
	inFile >> t_aliveBCond;
	inFile.ignore();
	inFile >> t_breedCooldownI;
	inFile.ignore();
	inFile >> t_symbolC;
	inFile.ignore();
	inFile >> t_positionVec2.x;
	inFile.ignore();
	inFile >> t_positionVec2.y;
	inFile.ignore();
}
