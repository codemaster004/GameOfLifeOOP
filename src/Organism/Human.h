/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_HUMAN_H
#define GAMEOFLIFEOOP_HUMAN_H
#include <set>


#include "../Utility/Menu.h"
#include "../World.h"
#include "Animal.h"
#include "Organism.h"


class Human : public Animal {
public:
	Human() {
		t_initiativeI = 4;
		t_symbolC = 'H';
	}

	Vec2 step() override {
		const InputCommands commands = *t_enviromentWorld_p->getCommands();

		std::set<Vec2> enteredDirections;
		if (commands[Menu::HumanUp]) {
			enteredDirections.insert({0, -1});
		}
		if (commands[Menu::HumanDown]) {
			enteredDirections.insert({0, 1});
		}
		if (commands[Menu::HumanLeft]) {
			enteredDirections.insert({-1, 0});
		}
		if (commands[Menu::HumanRight]) {
			enteredDirections.insert({1, 0});
		}
		if (!enteredDirections.empty()) {
			// more or less random value
			return t_positionVec2 + *enteredDirections.begin();
		}
		return {-1, -1};
	}

	void collision(Organism* attacker, CollisionContext& context) override {}

	Organism* getNewInstance() override { return nullptr; }

	void serialize(std::ofstream& outFile) const override;
	void deserialize(std::ifstream& inFile) override;

	ORGANISM_IS_TYPE(Human);
	ORGANISM_IS_GROUP(Human);
};


#endif // GAMEOFLIFEOOP_HUMAN_H
