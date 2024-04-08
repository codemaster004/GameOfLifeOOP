/**
 * Created by Filip Dabkowski on 06/04/2024.
 */

#ifndef PLANT_H
#define PLANT_H
#include "Organism.h"


class Plant :public Organism{
public:
	Plant() { this->t_symbolC = 'p'; }

	Vec2 step() override {}
};



#endif //PLANT_H
