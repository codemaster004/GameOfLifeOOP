/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef SOSNOWSKYSHOGWEED_H
#define SOSNOWSKYSHOGWEED_H
#include "../Plant.h"


class SosnowskysHogweed : public Plant {
public:
	SosnowskysHogweed() {
		this->t_strengthI = 10;
		this->t_symbolC = 'h';
	}

	Vec2 step() override;
	void collision(Organism* attacker, CollisionContext& context) override;

	Organism* getNewInstance() override { return new SosnowskysHogweed(); }
};


#endif // SOSNOWSKYSHOGWEED_H
