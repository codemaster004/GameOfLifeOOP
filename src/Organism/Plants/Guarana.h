/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef GUARANA_H
#define GUARANA_H
#include "../Plant.h"


class Guarana : public Plant {
	Guarana() { this->t_symbolC = 'u'; }

	void collision(Organism* attacker, CollisionContext& context) override {
		if (attacker->isGroup(Animal)) {
			attacker->setStrength(attacker->getStrength() + 3); // increase strength by 3
		}
		Plant::collision(attacker, context); // for simple call to default
	}
};

#endif // GUARANA_H
