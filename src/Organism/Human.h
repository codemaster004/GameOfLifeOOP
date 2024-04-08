/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_HUMAN_H
#define GAMEOFLIFEOOP_HUMAN_H
#include "Organism.h"


class Human final : public Organism {
public:
	Human() {
		t_ageI = 4;
		t_symbolC = 'H';

		std::cout << "Constructor Human" << std::endl;
	}

	Vec2 step() override {};
};


#endif // GAMEOFLIFEOOP_HUMAN_H
