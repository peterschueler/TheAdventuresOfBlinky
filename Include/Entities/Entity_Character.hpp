#ifndef ENTITY_CHARACTER_HPP
#define ENTITY_CHARACTER_HPP

#include "Entity.hpp"

class Entity_Character : public Entity {
public:
	Entity_Character();
	virtual void update(sf::Time delta);
	virtual void setDirection(float vx, float vy);
	
	sf::FloatRect borders();
	
protected:
	virtual void animate();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void attachTexture();
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	sf::Vector2f direction;
	
private:
	enum AnimationStep {
		first_x,
		second_x,
		first_y,
		second_y,
		stepCount
	};
	AnimationStep steps;
};

#endif