#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "World.hpp"
#include "InputHandler.hpp"

class Game {
public:
	Game();
	void run();
	
private:
	void processInput();
	void update(sf::Time dt);
	void render();
	void pause();
	
private:
	sf::RenderWindow window;
	World world;
	bool isPaused;
	static const sf::Time secondsFameRatio;
	InputHandler handler;
};

#endif