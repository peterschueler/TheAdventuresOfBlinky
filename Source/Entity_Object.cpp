#include "../Include/Entities/Entity_Object.hpp"

#include "../Include/Utilities.hpp"

#include <iostream>

Entity_Object::Entity_Object(Type type) : type(type), direction(0,0), sprite() {
	attachTexture();
}

void Entity_Object::update(sf::Time delta) {
	animate();
}

void Entity_Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_Object::animate() {;
}

void Entity_Object::reset() {
}

void Entity_Object::setDirection(float vx, float vy) {
	direction.x = vx;
	direction.y = vy;
}

void Entity_Object::attachTexture() {
	std::string filePath;
	switch (type) {
		case tree:
			filePath = "Media/Textures/tree_01.png";
			break;
		case stone:
			filePath = "Media/Textures/stone_01.png";
			break;
		case button_fire:
			filePath = "Media/Textures/grass_button_03.png";
			break;
		case button_swap:
			filePath = "Media/Textures/grass_button_02.png";
			break;
	}
	if (texture.loadFromFile(filePath)) {
		sprite.setTexture(texture);
	} else {
		std::cout << "No tree?" << std::endl;
	}
}

sf::FloatRect Entity_Object::borders() {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}