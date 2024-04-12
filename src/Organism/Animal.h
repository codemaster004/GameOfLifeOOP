/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef ANIMAL_H
#define ANIMAL_H
#include "Organism.h"


class Animal : public Organism {

	static float envSizeBound(int newValue, int envSize);

	static Vec2 generateNewRandomPosition(Vec2 currectPos, const World* enviroment_p, int range,
										  bool allowNoMovement = false);

protected:
	int t_movementSpeedI_;

public:
	Animal() {
		t_movementSpeedI_ = 1;
		this->t_symbolC = '0';
	}

	Vec2 step() override;

	void collision(Organism* attacker, CollisionContext& context) override {}

	ORGANISM_IS_TYPE(Animal);
};


#endif // ANIMAL_H
