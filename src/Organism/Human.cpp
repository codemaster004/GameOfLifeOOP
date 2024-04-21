/**
 * @class Human
 * @file Human.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */
#include "Human.h"

#include <fstream>


void Human::serialize(std::ofstream& outFile) const {
	outFile << static_cast<int>(OrganismType::Human) << std::endl;
	Animal::serialize(outFile);
}

void Human::deserialize(std::ifstream& inFile) { Animal::deserialize(inFile); }
