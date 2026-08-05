#include "GameMap.h"
#include <iostream>



//=====
//| P |
//=====

void GameMap::GenerateMap()
{
	_tiles.clear();

	for (int i = 0; i < _mapY; i++)
	{
		for (int j = 0; j < _mapX; j++)
		{
			Tile* tile = new Tile(j, i, "Empty");
			_tiles.push_back(tile);
		}
	}
}

//print the game map
void GameMap::PrintMap() const
{
	int tile = 0;

	for (int i = 0; i < _mapY; i++)
	{
		for (int j = 0; j < _mapX; j++)
		{
			std::cout << "=====";
		}
		std::cout << "\n";
		for (int j = 0; j < _mapX; j++)
		{
			_tiles[tile]->Print();
			tile++;
		}
		std::cout << "\n";
	}

	for (int j = 0; j < _mapX; j++)
	{
		std::cout << "=====";
	}
}


//Setters

int GameMap::X() const
{
	return _mapX;
}

int GameMap::Y() const
{
	return _mapY;
}

int GameMap::EnemyCount() const
{
	return _numEnemies;
}

//Getters

void GameMap::X(int x)
{
	_mapX = x;
}

void GameMap::Y(int y)
{
	_mapY = y;
}

void GameMap::EnemyCount(int enemies)
{
	_numEnemies = enemies;
}
