#ifndef COMMAND_MOVE_HPP
#define COMMAND_MOVE_HPP

#include "Command.hpp"

class Command_Move : public Command {
public:
	Command_Move(float vx, float vy);
	virtual void execute(Entity& entity);
	virtual void stop();
	
private:
	float x;
	float y;
};

#endif