#ifndef ENTITY_TITLESCREEN_HPP
#define ENTITY_TITLESCREEN_HPP

#include "Entity.hpp"

class Entity_Titlescreen : public Entity {
public:
	Entity_Titlescreen();
	virtual void update(sf::Time delta);
	
	virtual void setDirection(float vx, float vy);
	virtual void animate();
	
	virtual sf::FloatRect borders();
	
	virtual void reset();
	
	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void attachTexture();
		
	private:
		sf::Sprite sprite;
		sf::Texture texture;
};

#endif