#ifndef ENTITY_OBJECT_HPP
#define ENTITY_OBJECT_HPP

#include "Entity.hpp"

class Entity_Object : public Entity {
public:
	enum Type {
		tree,
		stone,
		button_fire,
		button_swap,
	};
	
public:
	Entity_Object(Type type);
	virtual void update(sf::Time delta);
	
	virtual void setDirection(float vx, float vy);
	
	Type getType();
	virtual void animate();
	
	virtual sf::FloatRect borders();
	
	virtual void reset();

private:
	Type type;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f direction;
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setup(Type type);
	void attachTexture();
};

#endif