#include "../Include/Entities/Entity_Object.hpp"

#include <iostream>

Entity_Object::Entity_Object(Type type) : type(type), direction(0,0), sprite() {
	attachTexture();
}

void Entity_Object::update(sf::Time delta) {
}

void Entity_Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_Object::animate() {
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
		case maze_straight_01:
			filePath = "Media/Textures/maze_straight_01.png";
			break;
		case maze_straight_02:
			filePath = "Media/Textures/maze_straight_02.png";
			break;
		case maze_corner:
			filePath = "media/Textures/maze_corner_01.png";
			break;
		case maze_button_01:
			filePath = "Media/Textures/maze_button_01.png";
			break;
		case wall:
			filePath = "Media/Textures/wall_01.png";
			break;
		case stone:
			filePath = "Media/Textures/stone_01.png";
			break;
	}
	if (texture.loadFromFile(filePath)) {
		sprite.setTexture(texture);
	} else {
		std::cout << "No tree?" << std::endl;
	}
}
