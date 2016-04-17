#include "../Include/Entities/Entity_Background.hpp"

#include <iostream>

const unsigned int Entity_Background::sizeOfMap = 1024;

Entity_Background::Entity_Background() {
	attachTexture();
}

void Entity_Background::update(sf::Time delta) {
}

void Entity_Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	for (unsigned int i = 0; i < sizeOfMap; i++) {
		target.draw(tiles[i], states);
	}
}

void Entity_Background::animate() {
}

void Entity_Background::reset() {
}

void Entity_Background::setDirection(float vx, float vy) {
}

void Entity_Background::attachTexture() {
	sf::Texture texture;
	if (texture.loadFromFile("Media/Textures/grass_01.png")) {
		textures.push_back(texture);
	} else {
		std::cout << "Couldn't find grass texture!" << std::endl;
	}
	int y_position = 0;
	int x_position = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			sf::Sprite spr;
			spr.setPosition(i*32, j*32);
			spr.setTexture(textures.at(0));
			tiles.push_back(spr);
		}
	}
}

sf::FloatRect Entity_Background::borders() {
	return sf::FloatRect();
}
