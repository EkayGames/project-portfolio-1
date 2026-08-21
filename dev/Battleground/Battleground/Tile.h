#pragma once
#include <string>
#include "Position.h"

enum class EntityType
{
	Empty,
	Player,
	Enemy
};

class Tile
{
public:

	Tile(int x, int y, EntityType type) :
		_entityType(type)
	{
		_pos._xpos = x;
		_pos._ypos = y;
	}

	void Print() const;

	//Getters
	Position Pos() const;
	EntityType GetEntityType() const;


	//setters
	void Pos(int x, int y);
	void SetEntityType(EntityType type);

private:
	Position _pos;
	EntityType _entityType;
};

