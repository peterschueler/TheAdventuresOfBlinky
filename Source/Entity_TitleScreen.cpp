#include "../Include/Entities/Entity_TitleScreen.hpp"

#include <iostream>

Entity_Titlescreen::Entity_Titlescreen() {
	attachTexture();
}

void Entity_Titlescreen::update(sf::Time delta) {
}

void Entity_Titlescreen::setDirection(float vx, float vy) {
}

void Entity_Titlescreen::animate() {
}

sf::FloatRect Entity_Titlescreen::borders() {
	return sf::FloatRect();
}

void Entity_Titlescreen::reset() {
	setPosition(1000,1000);
}

void Entity_Titlescreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_Titlescreen::attachTexture() {
	if (texture.loadFromFile("Media/Textures/Title_Screen.png")) {
		sprite.setTexture(texture);
	}
}