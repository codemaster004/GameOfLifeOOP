/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef BELLADONNA_H
#define BELLADONNA_H
#include "../Plant.h"


class Belladonna : public Plant {
	Belladonna() {
		this->t_strengthI = 99;
		this->t_symbolC = 'b';
	}
};


#endif // BELLADONNA_H
