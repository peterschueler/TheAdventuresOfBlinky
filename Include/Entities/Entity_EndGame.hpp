#ifndef ENTITY_ENDGAME_HPP
#define ENTITY_ENDGAME_HPP

#include "Entity.hpp"

class Entity_EndGame : public Entity {
public:
	Entity_EndGame();
	virtual void update(sf::Time delta);
	
	virtual void setDirection(float vx, float fy);
	virtual void animate();
	
	virtual sf::FloatRect borders();
	
	virtual void reset();
	void setWinner(bool winner);
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void attachTexture();
	
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
	bool _winner;
};

#endif