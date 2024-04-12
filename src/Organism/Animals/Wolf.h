/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef WOLF_H
#define WOLF_H
#include "../Animal.h"


class Wolf : public Animal {
public:
	Wolf() {
		t_symbolC = 'W';
		t_strengthI = 9;
		t_initiativeI = 5;
	}
};


#endif // WOLF_H
