#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <SFML/Window/Event.hpp>

#include "Commands/Command_Types.hpp"

class InputHandler {
public:
	Command* handleInput(const sf::Event& event);
};

#endif