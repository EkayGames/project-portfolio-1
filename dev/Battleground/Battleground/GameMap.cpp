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
			Tile* tile = new Tile(j, i, EntityType::Empty);
			_tiles.push_back(tile);
		}
	}

	std::vector<int> usedTiles; //Keeps track of used tiles so enemies and players dont overlap
	GeneratePlayerPos(usedTiles);

	for (int i = 0; i < _numEnemies; i++) //generate new enemy for each _numEnemies
	{
		int newEnemy = GenerateEnemy(usedTiles);
		usedTiles.push_back(newEnemy);
		_tiles[newEnemy]->SetEntityType(EntityType::Enemy);
	}
}

//print the game map
void GameMap::PrintMap() 
{
	int tile = 0;
	UpdateMap();
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
void GameMap::GeneratePlayerPos(std::vector<int>& usedTiles)
{
	int playerTile = Helper::RandomNumberGenerator(0, _tiles.size() - 1);
	_tiles[playerTile]->SetEntityType(EntityType::Player);
	usedTiles.push_back(playerTile);

	_player->Pos(_tiles[playerTile]->Pos()._xpos, _tiles[playerTile]->Pos()._ypos);
}

//Generate an enemy with ID to assign to a tile. ID is random between number of tiles and cannot be used tile
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

	EnemyType randType = static_cast<EnemyType>(Helper::RandomNumberGenerator(
		static_cast<int>(EnemyType::WizardShroom), 
		static_cast<int>(EnemyType::LAST) - 1));

	int attack;
	int health;

	switch (randType)
	{
	case EnemyType::WizardShroom:
		attack = 5;
		health = 5;
		break;
	case EnemyType::Skeleton:
		attack = 3;
		health = 10;
		break;
	case EnemyType::Hippie:
		attack = 1;
		health = 25;
		break;
	}

		Enemy* newEnemy = new Enemy(health, attack, _tiles[enemyTile]->Pos(), randType);
		_enemies.push_back(newEnemy);




	return enemyTile;
}

//Internally updates the game maps status
void GameMap::UpdateMap()
{
	for (auto i : _tiles)
	{
		i->SetEntityType(EntityType::Empty);

		if (i->Pos()._xpos == _player->Pos()._xpos && //If Player pos matches tile pos, update entity type
			i->Pos()._ypos == _player->Pos()._ypos)
		{
			i->SetEntityType(EntityType::Player);
		}
		
		for (auto j : _enemies) //Check each active enemy
		{
			if (i->Pos()._xpos == j->Pos()._xpos && //If Enemy pos matches tile pos, update entity type
				i->Pos()._ypos == j->Pos()._ypos)
			{
				i->SetEntityType(EntityType::Enemy);
			}
		}
	}
}

void GameMap::GameReset()
{
	_player->Health(10);
	_enemies.clear();
}


//Getters

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

Player* GameMap::MapPlayer() const
{
	return _player;
}

std::vector<Enemy*>& GameMap::Enemies()
{
	return _enemies;
}

//Setters

void GameMap::X(int x)
{
	_mapX = x;
}

void GameMap::Y(int y)
{
	_mapY = y;
}

void GameMap::MapPlayer(Player* player)
{
	_player = player;
}

void GameMap::EnemyCount(int enemies)
{
	_numEnemies = enemies;
}