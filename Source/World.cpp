#include "../Include/World.hpp"

#include <iostream>

World::World(sf::RenderWindow& window) : window(window), entities(), currentMaze(sf::FloatRect(0,32,576,472), 0) {
	std::unique_ptr<Entity_Background> background(new Entity_Background());
	backgrounds.push_back(std::move(background));
	
	initTrees();
	initMaze(0);
	
	std::unique_ptr<Entity_Character> player(new Entity_Character(Entity_Character::Type::player));
	playerChar = player.get();
	playerChar->setPosition(32,470);
	playerChar->setScale(2.f, 2.f);
	entities.push_back(std::move(player));
	
	std::unique_ptr<Entity_Character> monster(new Entity_Character(Entity_Character::Type::monster));
	monsterChar = monster.get();
	monsterChar->setPosition(900,300);
	monsterChar->setScale(4.f, 4.f);
	monsterChar->setDirection(-150.f, 0.f);
	entities.push_back(std::move(monster));
}

void World::update(sf::Time delta) {
	for (auto& entity : entities) {
		entity->update(delta);
	}
}

void World::draw() {
	for (auto& back : backgrounds) {
		window.draw(*back);
	}
	for (auto& wall : mazeAndWalls) {
		window.draw(*wall);
	}
	for (auto& entity : entities) {
		window.draw(*entity);
	}
}

void World::input(Command* command) {
	checkCollision();
	command->execute(*playerChar);
}

void World::initMaze(unsigned int index) {

	for (auto& tile : currentMaze.getTiles()) {
		mazeAndWalls.push_back(std::move(tile));
	}
}

void World::initTrees() {
	int shift_x = 32;
	for (int i = 0; i < 13; i++) {
		std::unique_ptr<Entity_Object> tree(new Entity_Object(Entity_Object::Type::tree));
		tree->setPosition(shift_x+i*32, 472);
		entities.push_back(std::move(tree));
	}
}

void World::checkCollision() {
	if (playerChar->getPosition().x < 32) {
		playerChar->setPosition(32, playerChar->getPosition().y);
	} else if (playerChar->getPosition().x > 736) {
		playerChar->setPosition(736, playerChar->getPosition().y);
	} else if (playerChar->getPosition().y < 32) {
		playerChar->setPosition(playerChar->getPosition().x, 32);
	} else if (playerChar->getPosition().y > 536) {
		playerChar->setPosition(playerChar->getPosition().x, 536);
	} else if (playerChar->borders().intersects(monsterChar->borders())) {
		playerChar->setPosition(200, 300);
	}
}