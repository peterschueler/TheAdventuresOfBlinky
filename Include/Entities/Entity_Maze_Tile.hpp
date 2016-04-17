#ifndef ENTITY_MAZE_TILE_HPP
#define ENTITY_MAZE_TILE_HPP

#include "Entity.hpp"

class Entity_Maze_Tile : public Entity {
public:
	enum TextureInfo {
		maze_straight_01,
		maze_straight_02,
		maze_corner,
		maze_button_01,
		wall,
	};
	
	struct Type {
		Type(TextureInfo info, bool isButton) {
			_info = info;
			_isButton = isButton;
		};
		
		TextureInfo _info;
		bool _isButton;
	};
public:
	Entity_Maze_Tile(Type type);
	virtual void update(sf::Time delta);
	
	virtual void setDirection(float vx, float vy);
	virtual void animate();
	
	sf::FloatRect borders();
	
	void setType(Entity_Maze_Tile::Type type);
	void triggerButton();
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void attachTexture();
	
private:
	void changeTexture(Type type);
	
private:
	Type type;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f direction;
};

#endif