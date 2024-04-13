/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef ANTELOPE_H
#define ANTELOPE_H
#include "../Animal.h"


class Antelope : public Animal {
public:
	Antelope() {
		t_symbolC = 'A';
		t_strengthI = 4;
		t_initiativeI = 4;
		t_movementSpeedI = 2;
	}
};


#endif // ANTELOPE_H
