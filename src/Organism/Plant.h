/**
 * Created by Filip Dabkowski on 06/04/2024.
 */

#ifndef PLANT_H
#define PLANT_H
#include "Organism.h"


class Plant : public Organism {
public:
	Plant() { this->t_symbolC = 'p'; }

	Vec2 step() override { return {-1, -1}; }

	void collision(Organism* attacker, CollisionContext& context) override {}

	ORGANISM_IS_TYPE(Plant);
};


#endif // PLANT_H
