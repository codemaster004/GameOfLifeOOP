/**
 * Created by Filip Dabkowski on 09/04/2024.
 */

#ifndef COLLISIONCONTEXT_H
#define COLLISIONCONTEXT_H
#include "../Utility/Vec2.h"
#include "Organism.h"


class CollisionContext {
	Vec2& t_attackerFromVec2;

	int t_demageI;

public:
	CollisionContext(int attackDemage, Vec2& attackFrom) : t_attackerFromVec2(attackFrom), t_demageI(attackDemage) {}

	void resolveByFighting(Organism* defender, Organism* attacker) {}

	void resolveByDeflecting(Organism* attacker) {}

	void resolveByEscaping(Organism* defender) {}
};


#endif // COLLISIONCONTEXT_H
