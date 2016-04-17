#ifndef COMMAND_RESET_HPP
#define COMMAND_RESET_HPP

#include "Command.hpp"

class Command_Reset : public Command {
public:
	Command_Reset(bool reset);
	virtual void execute(Entity& entity);
	virtual void stop();
	
private:
	bool _reset; 
};

#endif