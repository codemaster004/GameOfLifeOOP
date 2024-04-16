/**
 * Created by Filip Dabkowski on 09/04/2024.
 */

#ifndef COLLISIONCONTEXT_H
#define COLLISIONCONTEXT_H
#include "../Utility/Vec2.h"
#include "Organism.h"


class CollisionContext {

	enum ResolvedBy {
		Fight,
		Deflect,
		Escape,
	};

	Vec2 t_attackFrom;
	Vec2 t_attackTo;

	Vec2& t_attackerMoveVec2;

	int t_demageI;

	bool t_wonByAttacker;

	ResolvedBy t_resolvedBy;

public:
	CollisionContext(int attackDemage, Vec2 attackFrom, Vec2& attackTo) :
		t_attackFrom(attackFrom), t_attackTo(attackTo), t_attackerMoveVec2(attackTo), t_demageI(attackDemage),
		t_wonByAttacker(false) {}

	void resolveByFighting(Organism* defender, Organism* attacker);

	void resolveByDeflecting(Organism* attacker);

	void resolveByEscaping(Organism* defender);

	void log() const;
};


#endif // COLLISIONCONTEXT_H
