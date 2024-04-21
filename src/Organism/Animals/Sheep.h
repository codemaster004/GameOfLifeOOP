/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef SHEEP_H
#define SHEEP_H
#include "../Animal.h"


class Sheep : public Animal {
public:
	Sheep() {
		t_symbolC = 'S';
		t_strengthI = 4;
		t_initiativeI = 4;
	}

	Organism* getNewInstance() override { return new Sheep(); }

	void Sheep::serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::Sheep) << std::endl;
		Animal::serialize(outFile);
	}

	ORGANISM_IS_TYPE(Sheep);
};


#endif // SHEEP_H
