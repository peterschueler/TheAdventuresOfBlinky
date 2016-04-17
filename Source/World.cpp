#include "../Include/World.hpp"

#include <iostream>
#include <random>

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
	
	initMonsters();
}

void World::update(sf::Time delta) {
	for (auto& entity : entities) {
		entity->update(delta);
	}
	for (auto& monster : monsters) {
		monster->setDirection(-50.f, 0.f);
		monster->update(delta);
	}
	bossMonster->animate();
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
	for (auto& monster : monsters) {
		window.draw(*monster);
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

void World::initMonsters() {
	std::uniform_int_distribution<> x_position(850, 1050);
	std::uniform_int_distribution<> y_position(32, 768);
	// six floaters and one big one.
	std::mt19937 gen;
	for (int i = 0; i < 6; i++) {
		std::unique_ptr<Entity_Character> monster(new Entity_Character(Entity_Character::Type::monster));
		monster->setPosition(x_position(gen)*i%850, y_position(gen)*i%400);
		monster->setScale(2.f, 2.f);
		monsters.push_back(std::move(monster));
	}
	
	std::unique_ptr<Entity_Character> monster(new Entity_Character(Entity_Character::Type::monster));
	bossMonster = monster.get();
	monster->setPosition(580,123);
	monster->setScale(4.f, 4.f);
	monsters.push_back(std::move(monster));
}

void World::resetMonster(Entity_Character& monster) {
	std::uniform_int_distribution<> x_position(850, 1050);
	std::uniform_int_distribution<> y_position(32, 768);
	// six floaters and one big one.
	std::mt19937 gen;
	monster.setPosition(x_position(gen), y_position(gen));
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
	}
	for (auto& monster : monsters) {
		if (playerChar->borders().intersects(monster->borders())) {
			playerChar->swapAppearance();
		}
		if (monster->getPosition().x < - 50) {
			resetMonster(*monster);
		}
	}
}