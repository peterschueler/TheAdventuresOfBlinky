#include "../Include/World.hpp"

#include <iostream>

World::World(sf::RenderWindow& window) : window(window), entities() {
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