/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef BELLADONNA_H
#define BELLADONNA_H
#include "../../World.h"
#include "../CollisionContext.h"
#include "../Plant.h"


class Belladonna : public Plant {
	Belladonna() {
		this->t_strengthI = 99;
		this->t_symbolC = 'b';
	}

	void collision(Organism* attacker, CollisionContext& context) override {
		if (attacker->isGroup(Animal)) {
			context.resolveByKillingBoth(this, attacker);
		} else {
			Plant::collision(attacker, context);
		}
	}
};


#endif // BELLADONNA_H
