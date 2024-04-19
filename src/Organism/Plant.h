/**
 * Created by Filip Dabkowski on 06/04/2024.
 */

#ifndef PLANT_H
#define PLANT_H
#include "CollisionContext.h"
#include "Organism.h"


class Plant : public Organism {
public:
	Plant() { this->t_symbolC = 'p'; }

	Vec2 step() override { return {-1, -1}; }

	void collision(Organism* attacker, CollisionContext& context) override {
		context.resolveByFighting(this, attacker);
	}

	ORGANISM_IS_TYPE(Plant);
	ORGANISM_IS_GROUP(Plant);
};


#endif // PLANT_H
