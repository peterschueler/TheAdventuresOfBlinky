#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

#include <vector>

#include "Commands/Command_Types.hpp"
#include "Entities/Entity_Types.hpp"
#include "Maze.hpp"

class World : public sf::NonCopyable {
public:
	explicit World(sf::RenderWindow& window);
	
	void update(sf::Time delta);
	void draw();
	
	void input(Command* command);
private:
	void initMaze(unsigned int index);
	void initTrees();
	void initMonsters();
	void resetMonster(Entity_Character& monster);
	void moveButton();
	void checkCollision();

private:
	sf::RenderWindow& window;
	
	std::vector<std::unique_ptr<Entity_Background> > backgrounds;
	std::vector<std::unique_ptr<Entity> > entities;
	std::vector<std::unique_ptr<Entity_Character> > monsters;
	std::vector<std::unique_ptr<Entity> > mazeAndWalls;
	
	Maze currentMaze;
	Entity_Character* playerChar;
	Entity_Character* bossMonster;
	
	Entity_Object* fireButton;
	Entity_Object* swapButton;
	
	float timer;
};

#endif