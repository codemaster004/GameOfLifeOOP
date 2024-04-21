/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef BELLADONNA_H
#define BELLADONNA_H
#include "../../World.h"
#include "../CollisionContext.h"
#include "../Plant.h"


class Belladonna : public Plant {
public:
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

	Organism* getNewInstance() override { return new Belladonna(); }

	void serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::Belladonna) << std::endl;
		Plant::serialize(outFile);
	}
};


#endif // BELLADONNA_H
