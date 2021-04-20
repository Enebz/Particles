#include "Game.h"

int main() {
	std::srand(std::time(NULL));
	Game particles("Particles!");
	particles.run();
}