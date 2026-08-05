#pragma once
#include <vector>
#include "Tile.h"

class GameMap
{
public:
	void GenerateMap();
	void PrintMap() const;

	//Getters

	int X() const;
	int Y() const;
	int EnemyCount() const;

	// Setters

	void X(int x);
	void Y(int y);
	void EnemyCount(int enemies);

private:
	std::vector<Tile*> _tiles;
	int _mapX = 5;
	int _mapY = 5;
	int _numEnemies;
};

