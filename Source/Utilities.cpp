#include "../Include/Utilities.hpp"

void centerSprite(sf::Sprite sprite) {
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}