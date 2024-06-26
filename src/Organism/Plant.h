/**
 * Created by Filip Dabkowski on 06/04/2024.
 */

#ifndef PLANT_H
#define PLANT_H
#include "CollisionContext.h"
#include "Organism.h"

#include <fstream>


class Plant : public Organism {
	int t_sowChancePrecenI = 5;

public:
	Plant() { this->t_symbolC = 'p'; }

	void sow();

	Vec2 step() override;

	void collision(Organism* attacker, CollisionContext& context) override {
		context.resolveByFighting(this, attacker);
	}

	void serialize(std::ofstream& outFile) const override;
	void deserialize(std::ifstream& inFile) override;

	ORGANISM_IS_TYPE(Plant);
	ORGANISM_IS_GROUP(Plant);
};


#endif // PLANT_H
