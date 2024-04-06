
#include "src/Organism/Human.h"
#include "src/World.h"
int main() {
	auto world = World();

	world.addOrganism(new Human());

	return 0;
}
