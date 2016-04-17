#include "../Include/Entities/Entity_Maze_Tile.hpp"

#include <iostream>

Entity_Maze_Tile::Entity_Maze_Tile(Type type) : type(type), sprite(), texture() {
	attachTexture();
}

void Entity_Maze_Tile::update(sf::Time delta) {
	move(direction * delta.asSeconds());
}

void Entity_Maze_Tile::setDirection(float vx, float vy) {
	direction.x = vx;
	direction.y = vy;
}

void Entity_Maze_Tile::animate() {
	// TODO: If I have time left at the end.
	// Might be nice to have some flickering here. 
}

void Entity_Maze_Tile::setType(Entity_Maze_Tile::Type type) {
	type = type;
	changeTexture(type);
}

void Entity_Maze_Tile::triggerButton() {
}

void Entity_Maze_Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Entity_Maze_Tile::attachTexture() {
	std::string filePath = "Media/Textures/maze_tiles.png";
	sf::IntRect rect;
	switch (type._info) {
		case maze_straight_01:
			rect = sf::IntRect(0,0,32,32);
			break;
		case maze_straight_02:
			rect = sf::IntRect(0,33,32,32);
			break;
		case maze_corner:
			rect = sf::IntRect(33,33,32,32);
			break;
		case maze_button_01:
			rect = sf::IntRect(0,67,32,32);
			break;
		case wall:
			filePath = "Media/Textures/wall_01.png";
			rect = sf::IntRect(0,0,32,32);
			break;
	}
	if (texture.loadFromFile(filePath)) {
		sprite.setTexture(texture);
		sprite.setTextureRect(rect);
	} else {
		std::cout << "Couldn't find texture for maze!" << std::endl;
	}
}

void Entity_Maze_Tile::changeTexture(Type type) {
	sf::IntRect rect;
	switch (type._info) {
		case maze_straight_01:
			rect = sf::IntRect(0,0,32,32);
			break;
		case maze_straight_02:
			rect = sf::IntRect(0,33,32,32);
			break;
		case maze_corner:
			rect = sf::IntRect(33,33,32,32);
			break;
		case maze_button_01:
			rect = sf::IntRect(0,67,32,32);
			break;
		case wall:
			rect = sf::IntRect(0,0,32,32);
			break;
	}
	sprite.setTextureRect(rect);
}

sf::FloatRect Entity_Maze_Tile::borders() {
	sf::FloatRect bounds = getTransform().transformRect(sprite.getGlobalBounds());
	return bounds;
}