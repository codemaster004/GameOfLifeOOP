/**
 * Created by Filip Dabkowski on 09/04/2024.
 */

#ifndef COLLISIONCONTEXT_H
#define COLLISIONCONTEXT_H
#include "../Utility/Vec2.h"
#include "Organism.h"


class CollisionContext {

	enum ResolvedBy {
		Uresolved,
		Fight,
		Deflect,
		Escape,
	};

	Vec2 t_attackFrom;
	Vec2 t_attackTo;

	int t_demageI;

	bool t_wonByAttacker;

	ResolvedBy t_resolvedBy;

	World* t_world_p;

public:
	CollisionContext(int attackDemage, Vec2 attackFrom, Vec2 attackTo, World* world) :
		t_attackFrom(attackFrom), t_attackTo(attackTo), t_demageI(attackDemage), t_wonByAttacker(false),
		t_world_p(world) {
		t_resolvedBy = Uresolved;
	}

	void resolveByFighting(Organism* defender, Organism* attacker);

	void resolveByDeflecting(Organism* attacker);

	void resolveByEscaping(Organism* defender, Organism* attacker);

	void resolveByKillingBoth(Organism* defender, Organism* attacker);

	void log() const;
};


#endif // COLLISIONCONTEXT_H
