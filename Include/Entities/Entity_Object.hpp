#ifndef ENTITY_OBJECT_HPP
#define ENTITY_OBJECT_HPP

#include "Entity.hpp"

class Entity_Object : public Entity {
public:
	enum Type {
		tree,
		wall,
		maze_straight_01,
		maze_straight_02,
		maze_corner,
		maze_button_01,
		stone,
		typeCount
	};
	
public:
	Entity_Object(Type type);
	virtual void update(sf::Time delta);
	
	virtual void setDirection(float vx, float vy);
	
	Type getType();
	virtual void animate();

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