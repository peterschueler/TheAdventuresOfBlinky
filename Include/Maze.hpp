#ifndef MAZE_HPP
#define MAZE_HPP

#include <SFML/Graphics.hpp>

#include <vector>

#include "Entities/Entity_Types.hpp"

class Maze {
public:
	Maze(sf::FloatRect size, unsigned int index);
	
	std::vector<std::unique_ptr<Entity_Maze_Tile> > getTiles();
	
private:
	void setup();

private:
	std::vector<std::unique_ptr<Entity_Maze_Tile> > tiles;
	// TODO: If I find time to add more levels...
	unsigned int index;
	sf::FloatRect size;
};

#endif