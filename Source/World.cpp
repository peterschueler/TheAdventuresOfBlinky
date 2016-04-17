#include "../Include/World.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

World::World(sf::RenderWindow& window) : window(window), entities(), currentMaze(sf::FloatRect(0,32,576,472), 0), timer(0) {
	std::unique_ptr<Entity_Background> background(new Entity_Background());
	backgrounds.push_back(std::move(background));
	
	initTrees();
	initMaze(0);
	
	std::unique_ptr<Entity_Object> button(new Entity_Object(Entity_Object::Type::button));
	fireButton = button.get();
	fireButton->setPosition(900, 1000);
	fireButton->setScale(3.f, 3.f);
	entities.push_back(std::move(button));
	
	std::unique_ptr<Entity_Object> sButton(new Entity_Object(Entity_Object::Type::button));
	swapButton = sButton.get();
	swapButton->setPosition(536, 64);
	swapButton->setScale(2.f, 2.f);
	entities.push_back(std::move(sButton));
	
	std::unique_ptr<Entity_Character> player(new Entity_Character(Entity_Character::Type::player));
	playerChar = player.get();
	playerChar->setPosition(32,470);
	playerChar->setScale(2.f, 2.f);
	entities.push_back(std::move(player));	
	
	initMonsters();
}

void World::update(sf::Time delta) {
	timer = timer + delta.asSeconds();
	if (timer > 3) {
		moveButton();
		timer = 0;
	}
	for (auto& entity : entities) {
		entity->update(delta);
	}
	for (auto& monster : monsters) {
		monster->setDirection(-80.f, 0.f);
		monster->update(delta);
		if (monster->getPosition().x < - 50) {
			resetMonster(*monster);
		}
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

int randomNumber(unsigned int min, unsigned int max) {
	return rand() % (max - min) + min;
}

void World::initMonsters() {
	// six floaters and one big one.
	for (int i = 0; i < 8; i++) {
		std::unique_ptr<Entity_Character> monster(new Entity_Character(Entity_Character::Type::monster));
		monster->setPosition(randomNumber(850, 1150)+64, randomNumber(32, 576));
		monster->setScale(2.f, 2.f);
		monsters.push_back(std::move(monster));
	}
	
	std::unique_ptr<Entity_Character> monster(new Entity_Character(Entity_Character::Type::monster));
	bossMonster = monster.get();
	monster->setPosition(567,180);
	monster->setScale(4.f, 4.f);
	monsters.push_back(std::move(monster));
}

void World::resetMonster(Entity_Character& monster) {
	monster.setPosition(randomNumber(850, 950), randomNumber(32, 576));
	monster.setDirection(monster.getDirection().x-8, monster.getDirection().y);
}

void World::moveButton() {
	fireButton->setPosition(randomNumber(64, 538), randomNumber(64, 738));
}

void World::checkCollision() {
	if (playerChar->borders().intersects(swapButton->borders())) {
		playerChar->swapAppearance(1);
	}
	if (playerChar->borders().intersects(fireButton->borders())) {
		if (bossMonster->addTransparency(3) >= 256) {
			std::cout << "You won!" << std::endl;
		}
	}
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
			playerChar->swapAppearance(0);
		}
	}
}