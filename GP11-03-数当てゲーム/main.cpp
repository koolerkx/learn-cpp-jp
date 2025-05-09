#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"

int main() {
	Game game = Game();

	game.start();

	std::cin.ignore();
	std::cin.get();

	return 0;
}