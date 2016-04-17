#ifndef ENTITY_CHARACTER_HPP
#define ENTITY_CHARACTER_HPP

#include "Entity.hpp"

class Entity_Character : public Entity {
public:
	enum Type {
		player,
		player_shifted,
		monster,
	};
	
public:
	Entity_Character(Type type);
	virtual void update(sf::Time delta);
	virtual void setDirection(float vx, float vy);
	sf::Vector2f getDirection() const;
	virtual void animate();
	
	unsigned int addTransparency(unsigned int value);
	
	sf::FloatRect borders();
	
	void swapAppearance(unsigned int trigger);
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void attachTexture();
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f direction;
	
	unsigned int transparencyValue;
	
	Type type;
	
	bool currentAppearance;
	
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