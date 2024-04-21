/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef ANTELOPE_H
#define ANTELOPE_H
#include "../Animal.h"


class Antelope : public Animal {
public:
	Antelope() {
		t_symbolC = 'A';
		t_strengthI = 4;
		t_initiativeI = 4;
		t_movementSpeedI = 2;
	}

	void collision(Organism* attacker, CollisionContext& context) override;

	Organism* getNewInstance() override { return new Antelope(); }

	void serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::Antelope) << std::endl;
		Animal::serialize(outFile);
	}

	ORGANISM_IS_TYPE(Antelope);
};


#endif // ANTELOPE_H
