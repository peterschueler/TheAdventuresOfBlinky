#ifndef ENTITY_CHARACTER_HPP
#define ENTITY_CHARACTER_HPP

#include "Entity.hpp"

class Entity_Character : public Entity {
public:
	enum Type {
		player,
		npc,
		typeCount
	};
	
public:
	Entity_Character(Type type);
	virtual void update(sf::Time delta);
	virtual void setDirection(float vx, float vy);
	virtual void animate();
	
	sf::FloatRect borders();
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void attachTexture();
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f direction;
	
	Type type;
	
private:
	enum AnimationStep {
		first_x,
		second_x,
		third_x,
		first_y,
		second_y,
		third_y,
		stepCount
	};
	AnimationStep steps;
};

#endif