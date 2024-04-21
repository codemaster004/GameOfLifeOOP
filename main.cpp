
#include "src/World.h"

#include "src/Organism/Animals/Antelope.h"
#include "src/Organism/Animals/Fox.h"
#include "src/Organism/Animals/Turtle.h"
#include "src/Organism/Animals/Wolf.h"

#include "src/Organism/Human.h"

#include "src/Organism/Plants/Grass.h"
#include "src/Organism/Plants/SosnowskysHogweed.h"


int main() {
	auto world = World(7);

	// world.addOrganism(new Human(), 0, 0);

#define TEST_ANIMAL new Wolf()
	// world.addOrganism(TEST_ANIMAL, 2, 1);
	// world.addOrganism(TEST_ANIMAL, 1, 2);
	// world.addOrganism(TEST_ANIMAL, 3, 2);
	// world.addOrganism(TEST_ANIMAL, 2, 3);
	//
	// world.addOrganism(new Antelope(), 4, 4);
	//
	// world.addOrganism(new Fox(), 2, 2);
	//
	// world.addOrganism(new SosnowskysHogweed(), 3, 3);
	//
	// world.addOrganism(new Antelope(), 3, 4);
	// world.addOrganism(new Antelope(), 4, 3);
	// world.addOrganism(new Antelope(), 0, 0);
	// world.addOrganism(new Antelope(), 0, 1);
	// world.addOrganism(new Antelope(), 1, 0);

	world.loadGameState();

	world.drawWorld();
	std::cout << std::endl;

	for (int i = 0; i < 10; ++i) {
		world.updateWorld();
		world.drawWorld();
		std::cout << std::endl;
	}

	world.saveGamaState();

	return 0;
}
