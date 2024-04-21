/**
 * Created by Filip Dabkowski on 07/04/2024.
 */

#ifndef SOWTHISTLE_H
#define SOWTHISTLE_H
#include "../Plant.h"


class SowThistle : public Plant {
public:
	SowThistle() { this->t_symbolC = 's'; }

	Organism* getNewInstance() override { return new SowThistle(); }

	void serialize(std::ofstream& outFile) const override {
		outFile << static_cast<int>(OrganismType::SowThistle) << std::endl;
		Plant::serialize(outFile);
	}
};


#endif // SOWTHISTLE_H
