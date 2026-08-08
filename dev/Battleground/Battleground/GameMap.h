#pragma once
#include <vector>
#include "Tile.h"
#include "Enemy.h"
#include "Player.h"

class GameMap
{
public:
	void GenerateMap();
	void PrintMap();
	void GeneratePlayer(std::vector<int>& usedTiles);
	int GenerateEnemy(std::vector<int>& usedTiles);
	void UpdateMap();
	
	//Getters

	int X() const;
	int Y() const;
	int EnemyCount() const;
	Player* MapPlayer() const;
	std::vector<Enemy*> Enemies() const;


	// Setters

	void X(int x);
	void Y(int y);
	void EnemyCount(int enemies);

private:
	std::vector<Tile*> _tiles;
	int _mapX = 5;
	int _mapY = 5;
	int _numEnemies = 3;
	Player* _player;
	std::vector<Enemy*> _enemies;
};

