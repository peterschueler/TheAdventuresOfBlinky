#ifndef ENTITY_BACKGROUND_HPP
#define ENTITY_BACKGROUND_HPP

#include <vector>

#include "Entity.hpp"

class Entity_Background : public Entity {
public:
	Entity_Background();
	
	virtual void update(sf::Time delta);
	virtual void setDirection(float vx, float vy);
	virtual void animate();
	
	sf::FloatRect borders();
	
	virtual void reset();
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void attachTexture();
	
private:
	std::vector<sf::Sprite> tiles;
	std::vector<sf::Texture> textures;
	
	static const unsigned int sizeOfMap;
};

#endif