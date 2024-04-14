/**
 * @file Turtle.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 14/04/2024
 */
#include "Turtle.h"

Vec2 Turtle::step() {
	// 75% random ckeck not to move
	if (getRandom(0, 3) != 0) {
		return {-1, -1};
	}
	return Animal::step();
}
