/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_ORGANISM_H
#define GAMEOFLIFEOOP_ORGANISM_H

#include "../Utility/Vec2.h"


class Organism {
	int strength;
	int initiative;
	Vec2 position;

public:
	Organism() = delete;

	virtual void action() = 0;

	virtual void draw() = 0;
};


#endif //GAMEOFLIFEOOP_ORGANISM_H
