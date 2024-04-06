/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_ORGANISM_H
#define GAMEOFLIFEOOP_ORGANISM_H

#include <iostream>

#include "../Utility/Vec2.h"


class Organism {
protected:
	int strengthI_;
	int initiativeI_;

	int ageI_;


	Vec2 positionVec2_;

public:
	Organism() : strengthI_(0), initiativeI_(0), ageI_(0), positionVec2_() {
		std::cout << "Constructor Organism" << std::endl;
	}

	virtual void action() = 0;

	virtual void draw() = 0;

	/* Getters & Setters */

	[[nodiscard]] int getStrength() const { return strengthI_; }

	void setStrength(int strength) { this->strengthI_ = strength; }

	[[nodiscard]] int getInitiative() const { return initiativeI_; }

	void setInitiative(int initiative) { this->initiativeI_ = initiative; }

	[[nodiscard]] int getAge() const { return ageI_; }

	void setAge(int age) { this->ageI_ = age; }

	virtual ~Organism() { std::cout << "Destructor Organism" << std::endl; }
};


#endif // GAMEOFLIFEOOP_ORGANISM_H
