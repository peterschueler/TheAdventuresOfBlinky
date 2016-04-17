#include "../Include/InputHandler.hpp"

#include <iostream>

Command* InputHandler::handleInput(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Down) {
			return new Command_Move(0.f, +200.f);
		} else if (event.key.code == sf::Keyboard::Up) {
			return new Command_Move(0.f, -200.f);
		} else if (event.key.code == sf::Keyboard::Left) {
			return new Command_Move(-200.f, 0.f);
		} else if (event.key.code == sf::Keyboard::Right) {
			return new Command_Move(+200.f, 0.f);
		} else if (event.key.code == sf::Keyboard::S) {
			return new Command_Reset(true);
		}
	}
	return new Command_Empty();
}