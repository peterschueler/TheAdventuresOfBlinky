#include "../Include/InputHandler.hpp"

#include <iostream>

Command* InputHandler::handleInput(const sf::Event& event) {
	return new Command_Empty();
}