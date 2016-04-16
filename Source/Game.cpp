#include "../Include/Game.hpp"

const sf::Time Game::secondsFameRatio = sf::seconds(1.f/60.f);

Game::Game() : window(sf::VideoMode(800,600), "The Adventures of Blinky"), world(window), handler() {
}

void Game::run() {
	sf::Clock clock;
	sf::Time lastUpdate = sf::Time::Zero;
	while (window.isOpen()) {
		lastUpdate += clock.restart();
		while (lastUpdate > secondsFameRatio) {
			lastUpdate -= secondsFameRatio;
			
			processInput();
			update(secondsFameRatio);
		}
		render();
	}
}

void Game::processInput() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		world.input(handler.handleInput(event));
	}
}

void Game::update(sf::Time delta) {
	if (!isPaused) {
		world.update(delta);
	}
}

void Game::render() {
	window.clear();
	world.draw();
	window.display();
}