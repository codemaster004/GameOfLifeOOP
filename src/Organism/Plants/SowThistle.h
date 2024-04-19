/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef SOWTHISTLE_H
#define SOWTHISTLE_H
#include "../Plant.h"


class SowThistle : public Plant {
	SowThistle() { this->t_symbolC = 's'; }

	Organism* getNewInstance() override { return new SowThistle(); }
};


#endif // SOWTHISTLE_H
