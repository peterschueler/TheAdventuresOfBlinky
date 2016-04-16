#include "../Include/World.hpp"

#include <iostream>

World::World(sf::RenderWindow& window) : window(window), entities() {
	std::unique_ptr<Entity_Background> background(new Entity_Background());
	entities.push_back(std::move(background));
	
	std::unique_ptr<Entity_Object> tree01(new Entity_Object(Entity_Object::Type::tree));
	tree01->setPosition(150, 100);
	entities.push_back(std::move(tree01));
	
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
}

void World::input(Command* command) {
	for (auto& entity : entities) {
		command->execute(*entity);
	}
}

void World::initMaze() {
	
}