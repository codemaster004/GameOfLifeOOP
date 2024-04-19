/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef ANIMAL_H
#define ANIMAL_H
#include "CollisionContext.h"
#include "Organism.h"


class Animal : public Organism {
protected:
	static int envSizeBound(int newValue, int envSize);

	static Vec2 generateRandomPosition(Vec2 currectPos, const World* enviroment_p, int range, bool canStay = false);

	int t_movementSpeedI;

public:
	Animal() {
		t_movementSpeedI = 1;
		this->t_symbolC = '0';
	}

	Vec2 step() override;

	void collision(Organism* attacker, CollisionContext& context) override;

	ORGANISM_IS_TYPE(Animal);
	ORGANISM_IS_GROUP(Animal);
};

#endif // ANIMAL_H
