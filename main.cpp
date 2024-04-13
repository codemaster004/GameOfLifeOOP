
#include "src/Organism/Animals/Fox.h"
#include "src/Organism/Animals/Wolf.h"
#include "src/Organism/Human.h"
#include "src/Organism/Plants/Grass.h"
#include "src/World.h"


int main() {
	auto world = World(5);

	// world.addOrganism(new Human(), 0, 0);

#define TEST_ANIMAL new Wolf()
	world.addOrganism(TEST_ANIMAL, 1, 1);
	world.addOrganism(TEST_ANIMAL, 1, 2);
	world.addOrganism(TEST_ANIMAL, 1, 3);
	world.addOrganism(TEST_ANIMAL, 3, 1);
	world.addOrganism(TEST_ANIMAL, 3, 2);
	world.addOrganism(TEST_ANIMAL, 3, 3);
	// world.addOrganism(TEST_ANIMAL, 2, 1);
	world.addOrganism(TEST_ANIMAL, 2, 3);


	world.addOrganism(new Fox(), 2, 2);

	world.drawWorld();

	std::cout << std::endl;

	world.updateWorld();

	world.drawWorld();

	return 0;
}
