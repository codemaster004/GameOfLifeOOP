/**
 * @class CollisionContext
 * @file CollisionContext.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 09/04/2024
 */
#include "CollisionContext.h"
#include "../World.h"

#include <set>


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

void CollisionContext::resolveByEscaping(Organism* defender, Organism* attacker) {
	t_resolvedBy = Escape;
	std::set<Vec2> availablePosition;
	t_world_p->getAvailableSpotsAround(availablePosition, defender->getPossition());

	if (!availablePosition.empty()) {
		// ranadom posisiton from available posiition around the defender
		Vec2 randomPos = *availablePosition.begin();
		t_attackFrom = defender->getPossition(); // update for log

		// defender escapse its possiiton
		defender->moveTo(randomPos);

		// move atacker to where the defender was
		attacker->moveTo(t_attackTo);

		t_attackTo = randomPos; // update for log
	} else {
		// in case there are no availbale spots around resolve by fight
		this->resolveByFighting(defender, attacker);
	}
}

void CollisionContext::log() const {
	switch (t_resolvedBy) {
		case Fight:
			std::cout << "Fight ";
			break;
		case Deflect:
			std::cout << "Deflect ";
			break;
		case Escape:
			std::cout << "Escape ";
			break;
		case Uresolved:
			break;
	}
	std::cout << "Move from: (" << t_attackFrom.x << ", " << t_attackFrom.y << ") to: (" << t_attackTo.x << ", "
			  << t_attackTo.y << ") "
			  << "won by: " << (t_wonByAttacker ? "attacker" : "defender") << std::endl;
}
