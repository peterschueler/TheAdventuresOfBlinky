#include "../Include/Maze.hpp"

#include <iostream>

Maze::Maze(sf::FloatRect size, unsigned int index) : index(index), size(size) {
	setup();
}

std::vector<Entity_Maze_Tile*> Maze::getTiles() {
	return std::move(tiles);
}

void Maze::setup() {	
	unsigned int x_position; 
	for (int i = 0; i < 25; i++) {
		Entity_Maze_Tile* upper(new Entity_Maze_Tile(Entity_Maze_Tile::Type(Entity_Maze_Tile::wall, false)));
		upper->setPosition(i*32, 0);
		tiles.push_back(std::move(upper));
		
		Entity_Maze_Tile* lower(new Entity_Maze_Tile(Entity_Maze_Tile::Type(Entity_Maze_Tile::wall, false)));
		lower->setPosition(i*32, 568);
		tiles.push_back(std::move(lower));
	}
	unsigned int y_position;
	for (int i = 0; i < 19; i++) {
		Entity_Maze_Tile* left(new Entity_Maze_Tile(Entity_Maze_Tile::Type(Entity_Maze_Tile::wall, false)));
		left->setPosition(0, i*32);
		tiles.push_back(std::move(left));
		
		Entity_Maze_Tile* right(new Entity_Maze_Tile(Entity_Maze_Tile::Type(Entity_Maze_Tile::wall, false)));
		right->setPosition(768, i*32);
		tiles.push_back(std::move(right));
	}
	
	
	unsigned int lowerInset = size.top + size.height;
	unsigned int first_Corner_x;
	unsigned int first_Corner_y;
	unsigned int second_Corner_x;
	unsigned int second_Corner_y;
	unsigned int third_Corner_x;
	unsigned int third_Corner_y;
	for (int i = 0; i < 22; i++) {
		float shift = (i*64);
		Entity_Maze_Tile* tile(new Entity_Maze_Tile(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_straight_01, false)));
		tile->setScale(2.f, 2.f);
		switch (i) {
			case 0:
			case 1: 
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
				tile->setPosition(shift, lowerInset);
				tile->setRotation(0.f);
				break;
			case 7:
				tile->setType(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_corner, false));
				tile->setPosition(shift, lowerInset);
				break;
			case 8:
				tile->setType(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_straight_01, false));
				first_Corner_x = shift-64;
				first_Corner_y = lowerInset-64;
				tile->setPosition(first_Corner_x+64, first_Corner_y);
				tile->setRotation(90.f);
				break;
			case 9:
			case 10:
			case 11:
			case 12:
				tile->setType(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_straight_01, false));
				first_Corner_y-=64;
				tile->setPosition(first_Corner_x+64, first_Corner_y);
				tile->setRotation(90.f);
				break;
			case 13:
				second_Corner_y=first_Corner_y-64;
				tile->setType(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_corner, false));
				tile->setPosition(first_Corner_x, second_Corner_y+64);
				tile->setRotation(-90.f);
				break;
			case 14:
			case 15:
			case 16:
			case 17:
				tile->setType(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_straight_01, false));
				second_Corner_x = first_Corner_x-=64;
				tile->setPosition(second_Corner_x, second_Corner_y);
				break;
			case 18:
				tile->setType(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_corner, false));
				tile->setPosition(second_Corner_x, second_Corner_y);
				tile->setRotation(90.f);
				break;
			case 19:
			case 20:
			case 21:
				tile->setType(Entity_Maze_Tile::Type(Entity_Maze_Tile::maze_straight_01, false));
				third_Corner_y = second_Corner_y-=60;
				tile->setPosition(second_Corner_x, third_Corner_y);
				tile->setRotation(90.f);
				break;
			default:
				break;
		}
		tiles.push_back(std::move(tile));
	}
}