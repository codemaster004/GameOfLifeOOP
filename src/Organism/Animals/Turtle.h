/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef TURTLE_H
#define TURTLE_H
#include "../Animal.h"


class Turtle : public Animal {
public:
	Turtle() {
		t_symbolC = 'T';
		t_strengthI = 2;
		t_initiativeI = 1;
	}

	Vec2 step() override;

	void collision(Organism* attacker, CollisionContext& context) override;

	Organism* getNewInstance() override { return new Turtle(); }

	void Turtle::serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::Turtle) << std::endl;
		Animal::serialize(outFile);
	}

	ORGANISM_IS_TYPE(Turtle);
};


#endif // TURTLE_H
