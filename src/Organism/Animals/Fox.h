/**
 * Created by Filip Dabkowski on 08/04/2024.
 */

#ifndef FOX_H
#define FOX_H
#include "../Animal.h"


class Fox : public Animal {
public:
	Fox() {
		t_symbolC = 'F';
		t_strengthI = 3;
		t_initiativeI = 7;
	}
};


#endif // FOX_H
