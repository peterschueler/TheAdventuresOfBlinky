#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../Entity.hpp"

class Command {
public:
	virtual void execute(Entity& entity) = 0;
	virtual void stop() = 0;
};

#endif