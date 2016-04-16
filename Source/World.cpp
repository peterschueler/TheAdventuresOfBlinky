#include "../Include/World.hpp"

#include <iostream>

World::World(sf::RenderWindow& window) : window(window), entities() {
	std::unique_ptr<Entity_Background> background(new Entity_Background());
	entities.push_back(std::move(background));
	
	std::unique_ptr<Entity_Object> tree01(new Entity_Object(Entity_Object::Type::tree));
	tree01->setPosition(150, 100);
	entities.push_back(std::move(tree01));
	
	initWall();
	initMaze();
	
	std::unique_ptr<Entity_Character> player(new Entity_Character(Entity_Character::Type::player));
	player->setPosition(200,400);
	player->setScale(2.f, 2.f);
	entities.push_back(std::move(player));
}

void World::update(sf::Time delta) {
	for (auto& entity : entities) {
		entity->update(delta);
	}
}

void World::draw() {
	for (auto& entity : entities) {
		window.draw(*entity);
	}
	for (auto& tile : tiles) {
		window.draw(*tile);
	}
	for (auto& wall : walls) {
		window.draw(*wall);
	}
}

void World::input(Command* command) {
	for (auto& entity : entities) {
		command->execute(*entity);
	}
}

void World::initWall() {
	unsigned int x_position; 
	for (int i = 0; i < 25; i++) {
		std::unique_ptr<Entity_Object> upper(new Entity_Object(Entity_Object::Type::wall));
		upper->setPosition(i*32, 0);
		walls.push_back(std::move(upper));
		
		std::unique_ptr<Entity_Object> lower(new Entity_Object(Entity_Object::Type::wall));
		lower->setPosition(i*32, 568);
		walls.push_back(std::move(lower));
	}
	unsigned int y_position;
	for (int i = 0; i < 19; i++) {
		std::unique_ptr<Entity_Object> left(new Entity_Object(Entity_Object::Type::wall));
		left->setPosition(0, i*32);
		walls.push_back(std::move(left));
		
		std::unique_ptr<Entity_Object> right(new Entity_Object(Entity_Object::Type::wall));
		right->setPosition(768, i*32);
		walls.push_back(std::move(right));
	}
}

void World::initMaze() {
}