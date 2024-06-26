/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef GUARANA_H
#define GUARANA_H
#include "../Plant.h"


class Guarana : public Plant {
public:
	Guarana() { this->t_symbolC = 'u'; }

	void collision(Organism* attacker, CollisionContext& context) override {
		if (attacker->isGroup(Animal)) {
			attacker->setStrength(attacker->getStrength() + 3); // increase strength by 3
		}
		Plant::collision(attacker, context); // for simple call to default
	}

	Organism* getNewInstance() override { return new Guarana(); }

	void serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::Guarana) << std::endl;
		Plant::serialize(outFile);
	}
};

#endif // GUARANA_H
