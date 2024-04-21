/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_ORGANISM_H
#define GAMEOFLIFEOOP_ORGANISM_H

#include "../Utility/Core.h"
#include "../Utility/Vec2.h"

#include <iostream>


// Forward definitions for pointers
class World;

class CollisionContext;

class Organism {
protected:
	int t_strengthI;
	int t_initiativeI;

	int t_ageI;
	bool t_aliveBCond;
	int t_breedCooldownI;

	char t_symbolC;

	Vec2 t_positionVec2;

	World* t_enviromentWorld_p;

public:
	enum class OrganismType {
		Human,

		Plant,
		Animal,

		Antelope,
		Fox,
		Sheep,
		Turtle,
		Wolf,

		Belladonna,
		Grass,
		Guarana,
		SosnowskysHogweed,
		SowThistle,
	};

	enum OrganismGroup {
		Plant = BIT(0),
		Animal = BIT(1),
		Human = BIT(1) | BIT(2),
	};

	Organism() :
		t_strengthI(0), t_initiativeI(0), t_ageI(0), t_aliveBCond(true), t_breedCooldownI(1), t_symbolC('O'),
		t_positionVec2(), t_enviromentWorld_p(nullptr) {}

	virtual Vec2 step() = 0;
	virtual void draw() { std::cout << t_symbolC; }

	virtual Organism* getNewInstance() = 0;

	bool isWeakerThan(const Organism* other) const;
	bool isStrongerThan(const Organism* other) const;

	void moveTo(Vec2 destination);
	void removeFromWorld() const;

	static int getRandom(int from, int to);

	/* Getters & Setters */

	[[nodiscard]] int getStrength() const { return t_strengthI; }
	void setStrength(int strength) { this->t_strengthI = strength; }

	[[nodiscard]] int getInitiative() const { return t_initiativeI; }
	void setInitiative(int initiative) { this->t_initiativeI = initiative; }

	[[nodiscard]] int getAge() const { return t_ageI; }
	void setAge(int age) { this->t_ageI = age; }

	[[nodiscard]] bool isAlive() const { return t_aliveBCond; }
	void unalive() { this->t_aliveBCond = false; }

	[[nodiscard]] Vec2 getPossition() const { return t_positionVec2; }
	[[nodiscard]] int getX() const { return t_positionVec2.x; }
	[[nodiscard]] int getY() const { return t_positionVec2.y; }
	void setPosition(int x, int y) { this->t_positionVec2 = Vec2{x, y}; }
	void setPosition(Vec2 newPos) { this->t_positionVec2 = newPos; }

	void setEnviroment(World* enviroment) { this->t_enviromentWorld_p = enviroment; }

	[[nodiscard]] bool canBreed() const { return t_breedCooldownI <= 0; }
	void setBreedColldown() { t_breedCooldownI = 2; }
	void updateBreedColldown() { t_breedCooldownI > 0 && t_breedCooldownI--; }

	virtual void serialize(std::ofstream& outFile) const = 0;
	virtual void deserialize(std::ifstream& inFile) = 0;

	static Organism* createOrganism(OrganismType type);

	/* Type & Group */

	[[nodiscard]] virtual bool isType(OrganismType other) const = 0;
	[[nodiscard]] virtual OrganismType getType() const = 0;
	[[nodiscard]] virtual bool isGroup(OrganismGroup other) const = 0;

	/* Collision */

	virtual void collision(Organism* attacker, CollisionContext& context) = 0;

	/* Destruction */

	virtual ~Organism() = default;
};

#define ORGANISM_IS_TYPE(type)                                                                                         \
	[[nodiscard]] bool isType(Organism::OrganismType other) const override { return other == OrganismType::type; };    \
	[[nodiscard]] OrganismType getType() const override { return OrganismType::type; }
#define ORGANISM_IS_GROUP(group)                                                                                       \
	[[nodiscard]] bool isGroup(Organism::OrganismGroup other) const override {                                         \
		return (other & OrganismGroup::group) == OrganismGroup::group;                                                 \
	}


#endif // GAMEOFLIFEOOP_ORGANISM_H
