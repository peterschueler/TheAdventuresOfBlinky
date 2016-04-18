#include "../Include/Entities/Entity_EndGame.hpp"

#include <iostream>

Entity_EndGame::Entity_EndGame() : _winner(false) {
}

void Entity_EndGame::update(sf::Time delta) {
}

void Entity_EndGame::setDirection(float vx, float vy) {
}

void Entity_EndGame::animate() {
}

sf::FloatRect Entity_EndGame::borders() {
	return sf::FloatRect();
}

void Entity_EndGame::reset() {
	setPosition(1000, 1000);
}

void Entity_EndGame::setWinner(bool winner) {
	if (winner) {
		if (texture.loadFromFile("Media/Textures/Win_Screen.png")) {
			sprite.setTexture(texture);
			setPosition(0,0);
		}
	} else {
		if (texture.loadFromFile("Media/Textures/Lose_Screen.png")) {
			sprite.setTexture(texture);
			setPosition(0,0);
		}
	}
}

void Entity_EndGame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_EndGame::attachTexture() {
	std::string filePath;
	if (_winner) {
		filePath = "Media/Textures/Win_Screen.png";
	} else {
		filePath = "Media/Textures/Lose_Screen.png";
	}
	if (texture.loadFromFile(filePath)) {
		sprite.setTexture(texture);
	}
}