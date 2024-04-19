/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_HUMAN_H
#define GAMEOFLIFEOOP_HUMAN_H
#include "Organism.h"


class Human : public Organism {
public:
	Human() {
		t_initiativeI = 4;
		t_symbolC = 'H';
	}

	Vec2 step() override { return {-1, -1}; }

	void collision(Organism* attacker, CollisionContext& context) override {}

	Organism* getNewInstance() override { return nullptr; }

	ORGANISM_IS_TYPE(Human);
	ORGANISM_IS_GROUP(Human);
};


#endif // GAMEOFLIFEOOP_HUMAN_H
