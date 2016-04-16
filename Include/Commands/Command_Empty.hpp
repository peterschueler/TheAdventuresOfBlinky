#ifndef COMMAND_EMPTY_HPP
#define COMMAND_EMPTY_HPP

#include "Command.hpp"

class Command_Empty : public Command {
public:
	virtual void execute(Entity& entity);
	virtual void stop();
};

#endif