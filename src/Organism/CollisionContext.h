/**
 * Created by Filip Dabkowski on 09/04/2024.
 */

#ifndef COLLISIONCONTEXT_H
#define COLLISIONCONTEXT_H
#include "../Utility/Vec2.h"
#include "Organism.h"


class CollisionContext {
	Organism* t_attackingOrganism;
	Vec2& t_attackerFromVec2;

	int t_demageI;

public:
	CollisionContext(Organism* attacker, Vec2& attackFrom) :
		t_attackingOrganism(attacker), t_attackerFromVec2(attackFrom), t_demageI(attacker->getStrength()) {}

	void resolveByFight();

	void resolveByDeflecting();

	void resolveByEscaping();
};


#endif // COLLISIONCONTEXT_H
