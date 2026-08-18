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
	void GeneratePlayerPos(std::vector<int>& usedTiles);
	int GenerateEnemy(std::vector<int>& usedTiles);
	void UpdateMap();
	void GameReset();
	
	//Getters

	int X() const;
	int Y() const;
	int EnemyCount() const;
	Player* MapPlayer() const;
	std::vector<Enemy*>& Enemies();


	// Setters

	void X(int x);
	void Y(int y);
	void MapPlayer(Player* player);
	void EnemyCount(int enemies);

private:
	std::vector<Tile*> _tiles;
	int _mapX = 5;
	int _mapY = 5;
	int _numEnemies = 3;
	Player* _player = nullptr;
	std::vector<Enemy*> _enemies;
};

