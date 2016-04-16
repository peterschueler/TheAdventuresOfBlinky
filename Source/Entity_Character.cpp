#include "../Include/Entities/Entity_Character.hpp"
#include "../Include/Utilities.hpp"

#include <iostream>

Entity_Character::Entity_Character(Type type) : sprite(), texture(), direction(), steps(AnimationStep::first_x) {
	centerSprite(sprite);
	
	attachTexture();
}

void Entity_Character::attachTexture() {
	std::string filePath;
	switch (type) {
		case player:
			filePath = "Media/Textures/blinky_grid.png";
			break;
	}
	sf::IntRect rect(0, 0, 32, 32);
	if (texture.loadFromFile(filePath)) {
		sprite.setTexture(texture);
		sprite.setTextureRect(rect);
	} else {
		std::cout << "Couldn't load texture for character!" << std::endl;
	}
}

void Entity_Character::update(sf::Time delta) {
	move(direction * delta.asSeconds());
}

void Entity_Character::setDirection(float vx, float vy) {
	std::cout << "x: " << vx << " y: " << vy << std::endl;
	direction.x = vx;
	direction.y = vy;
	animate();
}

void Entity_Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_Character::animate() {
	if (direction.x > 0) {
		if (steps == first_y || steps == second_y || steps == third_y) {
			steps = first_x;
		}
		if (steps == first_x) {
			sf::IntRect rect(0,66,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::second_x;
		} else if (steps == second_x) {
			sf::IntRect rect(33,66,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::third_x;
		} else if (steps == third_x) {
			sf::IntRect rect(66,66,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::first_x;
		}
	} else if (direction.x < 0) {
		if (steps == first_y || steps == second_y || steps == third_y) {
			steps = first_x;
		}
		if (steps == first_x) {
			sf::IntRect rect(0,100,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::second_x;
		} else if (steps == second_x) {
			sf::IntRect rect(33,100,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::third_x;
		} else if (steps == third_x) {
			sf::IntRect rect(66,100,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::first_x;
		}
	} else if (direction.y < 0) {
		std::cout << "should walk down here." << std::endl;
		if (steps == first_x || steps == second_x || steps == third_x) {
			steps = first_y;
		}
		if (steps == first_y) {
			sf::IntRect rect(0,33,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::second_y;
		} else if (steps == second_y) {
			sf::IntRect rect(33,33,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::third_y;
		} else if (steps == third_y) {
			sf::IntRect rect(66,33,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::first_y;
		}
	} else if (direction.y > 0) {
		std::cout << "should walk up here." << std::endl;
		if (steps == first_x || steps == second_x || steps == third_x) {
			steps = first_y;
		}
		if (steps == first_y) {
			sf::IntRect rect(0,0,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::second_y;
		} else if (steps == second_y) {
			sf::IntRect rect(33,0,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::third_y;
		} else if (steps == third_y) {
			sf::IntRect rect(67,0,32,32);
			sprite.setTextureRect(rect);
			steps = AnimationStep::first_y;
		}
	}
}

sf::FloatRect Entity_Character::borders() {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	// TODO: maybe add a fence?
	return bounds;
}