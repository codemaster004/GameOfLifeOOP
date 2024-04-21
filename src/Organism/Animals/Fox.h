/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef FOX_H
#define FOX_H
#include "../Animal.h"


class Fox : public Animal {
public:
	Fox() {
		t_symbolC = 'F';
		t_strengthI = 3;
		t_initiativeI = 7;
	}

	Vec2 step() override;

	Organism* getNewInstance() override { return new Fox(); }

	void Fox::serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::Fox) << std::endl;
		Animal::serialize(outFile);
	}

	ORGANISM_IS_TYPE(Fox);
};


#endif // FOX_H
