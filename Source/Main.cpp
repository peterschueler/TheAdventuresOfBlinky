#include "../config.h"
#include "../Include/Game.hpp"

#include <iostream>

int main() {
	try {
		Game game;
		game.run();
		std::cout << "***\n\nTHE ADVENTURES OF BLINKY, THE SQUARE-SHAPED ROUND-THING\n\n***" << std::endl;
	} catch (std::exception& e) {
		std::cout << "\nFAILED: " << e.what() << std::endl;
	}
}