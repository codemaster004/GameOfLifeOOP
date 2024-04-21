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

	void SosnowskysHogweed::serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::SosnowskysHogweed) << std::endl;
		Plant::serialize(outFile);
	}
};


#endif // SOSNOWSKYSHOGWEED_H
