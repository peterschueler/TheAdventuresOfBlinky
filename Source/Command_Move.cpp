#include "../Include/Commands/Command_Move.hpp"

Command_Move::Command_Move(float vx, float vy) : x(vx), y(vy) {
}

void Command_Move::execute(Entity& entity) {
	entity.setDirection(x, y);
}

void Command_Move::stop() {
	x = 0;
	y = 0;
}