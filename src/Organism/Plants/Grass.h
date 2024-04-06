/**
 * Created by Filip Dabkowski on 06/04/2024.
 */

#ifndef GRASS_H
#define GRASS_H
#include "../Plant.h"


class Grass : public Plant {
public:
	Grass() {
		symbolC_ = 'G';
	}

	void action() override {}
};


#endif // GRASS_H
