/**
 * @class CollisionContext
 * @file CollisionContext.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 09/04/2024
 */
#include "CollisionContext.h"


void CollisionContext::resolveByFighting(Organism* defender, Organism* attacker) {
	// if defender is stronger attacker dies
	if (defender->isStrongerThan(attacker)) {
		attacker->unalive();
		t_attackerMoveVec2 = {-1, -1};
	} else {
		// of attacker is stronger or exacly the same defender dies
		defender->unalive();
		t_wonByAttacker = true;
	}
}

void CollisionContext::resolveByDeflecting(Organism* attacker) {}

void CollisionContext::resolveByEscaping(Organism* defender) {}

void CollisionContext::log() const {
	std::cout << "Move from: (" << t_attackFrom.x << ", " << t_attackFrom.y << ") to: (" << t_attackTo.x << ", "
			  << t_attackTo.y << ") "
			  << "won by: " << (t_wonByAttacker ? "attacker" : "defender") << std::endl;
}
