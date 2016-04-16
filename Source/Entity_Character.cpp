#include "../Include/Entities/Entity_Character.hpp"
#include "../Include/Utilities.hpp"

#include <iostream>

Entity_Character::Entity_Character() : sprite(), texture(), direction(), steps(AnimationStep::first_x) {
	centerSprite(sprite);
	
	attachTexture();
}

void Entity_Character::attachTexture() {
	sf::IntRect rect(0, 0, 32, 32);
	if (texture.loadFromFile("Media/Textures/def.png")) {
		sprite.setTexture(texture);
		sprite.setTextureRect(rect);
	} else {
		std::cout << "Couldn't load texture!" << std::endl;
	}
}

void Entity_Character::update(sf::Time delta) {
	move(direction * delta.asSeconds());
}

void Entity_Character::setDirection(float vx, float vy) {
	direction.x = vx;
	direction.y = vy;
	animate();
}

void Entity_Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_Character::animate() {
}

sf::FloatRect Entity_Character::borders() {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	// TODO: maybe add a fence?
	return bounds;
}