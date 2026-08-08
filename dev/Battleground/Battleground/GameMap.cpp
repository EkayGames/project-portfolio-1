#include "GameMap.h"
#include "Helper.h"
#include <iostream>



//=====
//| P |
//=====

void GameMap::GenerateMap()
{
	_tiles.clear();

	//Add tiles
	for (int i = 0; i < _mapY; i++)
	{
		for (int j = 0; j < _mapX; j++)
		{
			Tile* tile = new Tile(j, i, "Empty");
			_tiles.push_back(tile);
		}
	}

	std::vector<int> usedTiles; //Keeps track of used tiles so enemies and players dont overlap
	GeneratePlayer(usedTiles);

	for (int i = 0; i < _numEnemies; i++) //generate new enemy for each _numEnemies
	{
		int newEnemy = GenerateEnemy(usedTiles);
		usedTiles.push_back(newEnemy);
		_tiles[newEnemy]->EntityType("Enemy");
	}
}

//print the game map
void GameMap::PrintMap() const
{
	int tile = 0;

	for (int i = 0; i < _mapY; i++)
	{
		for (int j = 0; j < _mapX; j++) //Print a line of correct length
		{
			std::cout << "=====";
		}
		std::cout << "\n";
		for (int j = 0; j < _mapX; j++) //Add center of tiles to row
		{
			_tiles[tile]->Print();
			tile++;
		}
		std::cout << "\n";
	}

	for (int j = 0; j < _mapX; j++) //Print a end line of correct length
	{
		std::cout << "=====";
	}

	std::cout << "\n\n";
}

//Generate and add a player to the map
void GameMap::GeneratePlayer(std::vector<int>& usedTiles)
{
	int playerTile = Helper::RandomNumberGenerator(0, _tiles.size() - 1);
	_tiles[playerTile]->EntityType("Player");
	usedTiles.push_back(playerTile);
}

//Generate an enemy ID to assign to a tile. ID is random between number of tiles and cannot be used tile
int GameMap::GenerateEnemy(std::vector<int>& usedTiles)
{
	int enemyTile = Helper::RandomNumberGenerator(0, _tiles.size() - 1);
	for (auto i : usedTiles)
	{
		if (enemyTile == i)
		{
			enemyTile = GenerateEnemy(usedTiles); //if enemy is on occupied tile rerun
		}
	}

	return enemyTile;
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
