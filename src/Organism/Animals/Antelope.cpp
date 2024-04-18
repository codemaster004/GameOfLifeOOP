/**
 * @file Antelope.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 18/04/2024
 */
#include "Antelope.h"


void Antelope::collision(Organism* attacker, CollisionContext& context) {
	// 50% chance to escape fight
	if (getRandom(0, 1) == 0) {
		context.resolveByEscaping(this, attacker);
	} else {
		context.resolveByFighting(this, attacker);
	}
}
