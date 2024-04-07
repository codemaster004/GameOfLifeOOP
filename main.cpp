
#include "src/Organism/Human.h"
#include "src/Organism/Plants/Grass.h"
#include "src/World.h"


int main() {
	auto world = World(3);

	world.addOrganism(new Human(), 0, 0);
	world.addOrganism(new Grass(), 1, 2);

	world.updateWorld();

	world.drawWorld();

	return 0;
}
