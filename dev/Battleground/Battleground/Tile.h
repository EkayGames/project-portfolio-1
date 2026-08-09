#pragma once
#include <string>
#include "Position.h"

class Tile
{
public:

	Tile(int x, int y, std::string type) :
		_entityType(type)
	{
		_pos._xpos = x;
		_pos._ypos = y;
	}

	void Print() const;

	//Getters
	Position Pos() const;
	std::string EntityType() const;


	//setters
	void Pos(int x, int y);
	void EntityType(std::string type);

private:
	Position _pos;
	std::string _entityType;
};

