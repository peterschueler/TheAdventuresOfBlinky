#include "../Include/Entities/Entity_Character.hpp"
#include "../Include/Utilities.hpp"

#include <iostream>

Entity_Character::Entity_Character(Type type) : sprite(), texture(), direction(), steps(AnimationStep::first_x), type(type), currentAppearance(true), transparencyValue(256) {
	centerSprite(sprite);
	
	attachTexture();
}

void Entity_Character::attachTexture() {
	std::string filePath;
	sf::IntRect rect;
	switch (type) {
		case player:
		case player_shifted:
			filePath = "Media/Textures/blinky_grid.png";
			rect = sf::IntRect(66, 66, 32, 32);
			break;
		case monster:
			filePath = "Media/Textures/monster_grid.png";
			rect = sf::IntRect(0,0,32,32);
			break;
	}
	if (texture.loadFromFile(filePath)) {
		sprite.setTexture(texture);
		sprite.setTextureRect(rect);
	} else {
		std::cout << "Couldn't load texture for character!" << std::endl;
	}
}

void Entity_Character::swapAppearance(unsigned int trigger) {
	if (type == player || player_shifted) {
		if (trigger == 0) {
			if (texture.loadFromFile("Media/Textures/monster_grid.png")) {
				sf::IntRect rect(0,0,32,32);
				sprite.setTexture(texture);
				sprite.setTextureRect(rect);
				type = Type(player_shifted);
				steps = first_x;
				currentAppearance = false;
			}
		} else if (trigger == 1) {
			if (texture.loadFromFile("Media/Textures/blinky_grid.png")) {
				sf::IntRect rect(0,0,32,32);
				sprite.setTexture(texture);
				sprite.setTextureRect(rect);
				type = Type(player);
				currentAppearance = true;
			}
		}
	}
}

void Entity_Character::update(sf::Time delta) {
	move(direction * delta.asSeconds());
}

void Entity_Character::setDirection(float vx, float vy) {
	if (getScale().x < 4.f && getScale().y < 4.f) {
		direction.x = vx;
		direction.y = vy;
		animate();
	}
}

sf::Vector2f Entity_Character::getDirection() const {
	return direction;
}

unsigned int Entity_Character::addTransparency(unsigned int value) {
	transparencyValue -= value;
	sprite.setColor(sf::Color(255, 255, 255, transparencyValue));
	return transparencyValue;
}

void Entity_Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_Character::reset() {
}

void Entity_Character::animate() {
 	if (type == monster || type == player_shifted) {
		if (steps == first_x) {
			sf::IntRect rect(33,0,32,32);
			sprite.setTextureRect(rect);
			steps = second_x;
		} else {
			sf::IntRect rect(0,0,32,32);
			sprite.setTextureRect(rect);
			steps = first_x;
		}
	} else if (type == player) {
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
}

sf::FloatRect Entity_Character::borders() {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	// TODO: maybe add a fence?
	return bounds;
}