/**
 * Created by Filip Dabkowski on 06/04/2024.
 */

#ifndef GRASS_H
#define GRASS_H
#include "../Plant.h"


class Grass : public Plant {
public:
	Grass() { t_symbolC = 'g'; }

	Organism* getNewInstance() override { return new Grass(); }

	void Grass::serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::Grass) << std::endl;
		Plant::serialize(outFile);
	}
};


#endif // GRASS_H
