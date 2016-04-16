#include "../Include/Commands/Command_Empty.hpp"

#include <iostream>

void Command_Empty::execute(Entity& entity) {
// 	std::cout << "do nothing for a while." << std::endl;
	entity.setDirection(0,0);
}

void Command_Empty::stop() {
}