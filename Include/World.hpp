#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

#include <vector>

#include "Commands/Command_Types.hpp"
#include "Entities/Entity_Types.hpp"

class World : public sf::NonCopyable {
public:
	explicit World(sf::RenderWindow& window);
	
	void update(sf::Time delta);
	void draw();
	
	void input(Command* command);
	
private:
	void initMaze();

private:
	sf::RenderWindow& window;
	
	std::vector<std::unique_ptr<Entity> > entities;
	std::vector<std::unique_ptr<Entity_Object> > mazeTiles;
};

#endif