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
	t_resolvedBy = Fight;
	// if defender is stronger attacker dies
	if (defender->isStrongerThan(attacker)) {
		attacker->unalive();
		attacker->removeFromWorld();
	} else {
		// of attacker is stronger or exacly the same defender dies
		defender->unalive();
		attacker->moveTo(t_attackTo);

		t_wonByAttacker = true;
	}
}

void CollisionContext::resolveByDeflecting(Organism* attacker) { t_resolvedBy = Deflect; }

void CollisionContext::resolveByEscaping(Organism* defender) { t_resolvedBy = Escape; }

void CollisionContext::log() const {
	switch (t_resolvedBy) {
		case Fight:
			std::cout << "Fight ";
			break;
		case Deflect:
			std::cout << "Deflect ";
			break;
		case Escape:
			break;
	}
	std::cout << "Move from: (" << t_attackFrom.x << ", " << t_attackFrom.y << ") to: (" << t_attackTo.x << ", "
			  << t_attackTo.y << ") "
			  << "won by: " << (t_wonByAttacker ? "attacker" : "defender") << std::endl;
}
