/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_ORGANISM_H
#define GAMEOFLIFEOOP_ORGANISM_H

#include <iostream>

#include "../Utility/Vec2.h"

#define ORGANISM_SYMBOL 'O'

// predefinition for pointer to world Organism is placed in
class World;


class Organism {
protected:
	int strengthI_;
	int initiativeI_;

	int ageI_;
	bool aliveBCond_;

	char symbolC_;

	Vec2 positionVec2_;

	World* enviromentWorld_p;

public:
	Organism() :
		strengthI_(0), initiativeI_(0), ageI_(0), aliveBCond_(true), symbolC_(ORGANISM_SYMBOL), positionVec2_(),
		enviromentWorld_p(nullptr) {
		std::cout << "Constructor Organism" << std::endl;
	}

	virtual void action() = 0;

	virtual void draw() { std::cout << symbolC_; }

	/* Getters & Setters */

	[[nodiscard]] int getStrength() const { return strengthI_; }
	void setStrength(int strength) { this->strengthI_ = strength; }

	[[nodiscard]] int getInitiative() const { return initiativeI_; }
	void setInitiative(int initiative) { this->initiativeI_ = initiative; }

	[[nodiscard]] int getAge() const { return ageI_; }
	void setAge(int age) { this->ageI_ = age; }

	[[nodiscard]] bool isAlive() const { return aliveBCond_; }
	void unalive() { this->aliveBCond_ = false; }

	[[nodiscard]] int getX() const { return static_cast<int>(positionVec2_.x); }
	[[nodiscard]] int getY() const { return static_cast<int>(positionVec2_.y); }
	void setPosition(int x, int y) { this->positionVec2_ = Vec2{static_cast<float>(x), static_cast<float>(y)}; }

	void setEnviroment(World* enviroment) { this->enviromentWorld_p = enviroment; }

	/* Destruction */

	virtual ~Organism() { std::cout << "Destructor Organism" << std::endl; }
};


#endif // GAMEOFLIFEOOP_ORGANISM_H
