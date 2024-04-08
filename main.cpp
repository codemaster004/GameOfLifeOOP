
#include "src/Organism/Animals/Fox.h"
#include "src/Organism/Human.h"
#include "src/Organism/Plants/Grass.h"
#include "src/World.h"


int main() {
	auto world = World(10);

	world.addOrganism(new Human(), 0, 0);
	world.addOrganism(new Grass(), 1, 2);
	world.addOrganism(new Fox(), 3, 2);

	world.drawWorld();

	world.updateWorld();

	std::cout << std::endl;

	world.drawWorld();

	return 0;
}
