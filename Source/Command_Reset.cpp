#include "../Include/Commands/Command_Reset.hpp"

Command_Reset::Command_Reset(bool reset) : _reset(reset) {
}

void Command_Reset::execute(Entity& entity) {
	if (_reset) {
		entity.reset();
	} else {
	}
}

void Command_Reset::stop() {
}