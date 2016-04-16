#include "../Include/Commands/Command_Empty.hpp"

#include <iostream>

void Command_Empty::execute(Entity& entity) {
	std::cout << "do nothing for a while." << std::endl;
}

void Command_Empty::stop() {
}