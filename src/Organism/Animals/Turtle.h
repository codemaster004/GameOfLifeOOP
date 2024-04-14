/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef TURTLE_H
#define TURTLE_H
#include "../Animal.h"


class Turtle : public Animal {
public:
	Turtle() {
		t_symbolC = 'T';
		t_strengthI = 2;
		t_initiativeI = 1;
	}

	Vec2 step() override;
};


#endif // TURTLE_H
