#include "../config.h"
#include "../Include/Game.hpp"

#include <iostream>

int main() {
	std::srand(std::time(0));
	try {
		std::cout << "***\n\nTHE ADVENTURES OF BLINKY, THE SQUARE-SHAPED ROUND-THING\n\n***" << std::endl;
		Game game;
		game.run();
	} catch (std::exception& e) {
		std::cout << "\nFAILED: " << e.what() << std::endl;
	}
}