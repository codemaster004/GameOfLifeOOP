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
	int t_strengthI;
	int t_initiativeI;

	int t_ageI;
	bool t_aliveBCond;

	char t_symbolC;

	Vec2 t_positionVec2;

	World* t_enviromentWorld_p;

public:
	Organism() :
		t_strengthI(0), t_initiativeI(0), t_ageI(0), t_aliveBCond(true), t_symbolC(ORGANISM_SYMBOL), t_positionVec2(),
		t_enviromentWorld_p(nullptr) {
		std::cout << "Constructor Organism" << std::endl;
	}

	virtual Vec2 step() = 0;

	virtual void draw() { std::cout << t_symbolC; }

	/* Getters & Setters */

	[[nodiscard]] int getStrength() const { return t_strengthI; }
	void setStrength(int strength) { this->t_strengthI = strength; }

	[[nodiscard]] int getInitiative() const { return t_initiativeI; }
	void setInitiative(int initiative) { this->t_initiativeI = initiative; }

	[[nodiscard]] int getAge() const { return t_ageI; }
	void setAge(int age) { this->t_ageI = age; }

	[[nodiscard]] bool isAlive() const { return t_aliveBCond; }
	void unalive() { this->t_aliveBCond = false; }

	[[nodiscard]] int getX() const { return static_cast<int>(t_positionVec2.x); }
	[[nodiscard]] int getY() const { return static_cast<int>(t_positionVec2.y); }
	void setPosition(int x, int y) { this->t_positionVec2 = Vec2{static_cast<float>(x), static_cast<float>(y)}; }

	void setEnviroment(World* enviroment) { this->t_enviromentWorld_p = enviroment; }

	/* Destruction */

	virtual ~Organism() { std::cout << "Destructor Organism" << std::endl; }
};


#endif // GAMEOFLIFEOOP_ORGANISM_H
