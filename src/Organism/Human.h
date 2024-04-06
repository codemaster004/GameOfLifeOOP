/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_HUMAN_H
#define GAMEOFLIFEOOP_HUMAN_H
#include "Organism.h"


class Human final : public Organism {
public:
	Human() {
		ageI_ = 4;
		std::cout << "Constructor Human" << std::endl;
	}

	void action() override {};
};


#endif // GAMEOFLIFEOOP_HUMAN_H
