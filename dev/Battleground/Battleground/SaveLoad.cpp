#include "SaveLoad.h"

//health, attack, pos, max health, healrate, size of powers vector, powers
void SaveLoad::PlayerSave(Player* player)
{

	int health = player->Health();
	int attack = player->Attack();
	int x = player->Pos()._xpos;
	int y = player->Pos()._ypos;
	int maxHealth = player->MaxHealth();
	int healRate = player->HealRate();

	int powersSize = player->Powers().size();

	std::ofstream outFile("player.bin", std::ios::binary | std::ios::trunc);


	if (outFile.is_open())
	{
		outFile.write(reinterpret_cast<const char*>(&health), sizeof(health));
		outFile.write(reinterpret_cast<const char*>(&attack), sizeof(attack));
		outFile.write(reinterpret_cast<const char*>(&x), sizeof(x));
		outFile.write(reinterpret_cast<const char*>(&y), sizeof(y));
		outFile.write(reinterpret_cast<const char*>(&maxHealth), sizeof(maxHealth));
		outFile.write(reinterpret_cast<const char*>(&healRate), sizeof(healRate));

		outFile.write(reinterpret_cast<const char*>(&powersSize), sizeof(powersSize));

		for (Power power : player->Powers())
		{
			outFile.write(reinterpret_cast<const char*>(&power), sizeof(power));
		}

		outFile.close();
	}
	else std::cout << "ERROR: FAILED TO OPEN FILE TO SAVE";
}
//map x, map y, current enemies, num enemies, num tiles, enemies, tiles,
void SaveLoad::MapSave(GameMap* map)
{
	int x = map->X();
	int y = map->Y();
	int currentEnemies = map->Enemies().size();
	int enemyCount = map->EnemyCount();
	int numTiles = map->Tiles().size();

	std::ofstream outFile("map.bin", std::ios::binary | std::ios::trunc);

	if (outFile.is_open())
	{
		outFile.write(reinterpret_cast<const char*>(&x), sizeof(x));
		outFile.write(reinterpret_cast<const char*>(&y), sizeof(y));
		outFile.write(reinterpret_cast<const char*>(&currentEnemies), sizeof(currentEnemies));
		outFile.write(reinterpret_cast<const char*>(&enemyCount), sizeof(enemyCount));
		outFile.write(reinterpret_cast<const char*>(&numTiles), sizeof(numTiles));

		for (Enemy* enemy : map->Enemies())
		{
			EnemySave(enemy, outFile);
		}

		for (auto tile : map->Tiles())
		{
			TileSave(tile, outFile);
		}

		outFile.close();
	}
	else std::cout << "ERROR: FAILED TO OPEN FILE TO SAVE";
}

void SaveLoad::EnemySave(Enemy* enemy, std::ofstream& outFile)
{
	int health = enemy->Health();
	int attack = enemy->Attack();
	int x = enemy->Pos()._xpos;
	int y = enemy->Pos()._ypos;
	EnemyType type = enemy->GetEnemyType();

	outFile.write(reinterpret_cast<const char*>(&health), sizeof(health));
	outFile.write(reinterpret_cast<const char*>(&attack), sizeof(attack));
	outFile.write(reinterpret_cast<const char*>(&x), sizeof(x));
	outFile.write(reinterpret_cast<const char*>(&y), sizeof(y));
	outFile.write(reinterpret_cast<const char*>(&type), sizeof(type));
}

void SaveLoad::TileSave(Tile* tile, std::ofstream& outFile)
{
	int x = tile->Pos()._xpos;
	int y = tile->Pos()._ypos;
	EntityType type = tile->GetEntityType();

	outFile.write(reinterpret_cast<const char*>(&x), sizeof(x));
	outFile.write(reinterpret_cast<const char*>(&y), sizeof(y));
	outFile.write(reinterpret_cast<const char*>(&type), sizeof(type));

}

Player* SaveLoad::PlayerLoad()
{

	int health = 0;
	int attack = 0;
	int x = 0;
	int y = 0;
	int maxHealth = 0;
	int healRate = 0;

	Player* player = new Player(0,0);

	Power power;

	int powerSize = 0;

	std::ifstream inFile("player.bin", std::ios::binary);

	if (inFile.is_open())
	{
		inFile.read(reinterpret_cast<char*>(&health), sizeof(health));
		inFile.read(reinterpret_cast<char*>(&attack), sizeof(attack));
		inFile.read(reinterpret_cast<char*>(&x), sizeof(x));
		inFile.read(reinterpret_cast<char*>(&y), sizeof(y));
		inFile.read(reinterpret_cast<char*>(&maxHealth), sizeof(maxHealth));
		inFile.read(reinterpret_cast<char*>(&healRate), sizeof(healRate));

		inFile.read(reinterpret_cast<char*>(&powerSize), sizeof(powerSize));

		player = new Player(health, attack, x, y, maxHealth, healRate);

		if (powerSize != 0)
		{
			for (int i = 0; i < powerSize; i++)
			{
				inFile.read(reinterpret_cast<char*>(&power), sizeof(power));
				player->ApplyPower(power);
			}
		}

		inFile.close();
	}
	else std::cout << "ERROR: FAILED TO OPEN FILE TO LOAD";


	return player;
}

void SaveLoad::MapLoad(GameMap* map)
{
	map->Enemies().clear();
	map->Tiles().clear();


	int x = 0;
	int y = 0;
	int currentEnemies = 0;
	int enemyCount = 0;
	int tileCount = 0;


	std::ifstream inFile("map.bin", std::ios::binary);

	if (inFile.is_open())
	{
		inFile.read(reinterpret_cast<char*>(&x), sizeof(x));
		inFile.read(reinterpret_cast<char*>(&y), sizeof(y));
		inFile.read(reinterpret_cast<char*>(&currentEnemies), sizeof(currentEnemies));
		inFile.read(reinterpret_cast<char*>(&enemyCount), sizeof(enemyCount));
		inFile.read(reinterpret_cast<char*>(&tileCount), sizeof(tileCount));

		map->X(x);
		map->Y(y);
		map->EnemyCount(enemyCount);


		for (int i = 0; i < currentEnemies; i++)
		{
			EnemyLoad(map, inFile);
		}

		for (int i = 0; i < tileCount; i++)
		{
			TileLoad(map, inFile);
		}

		inFile.close();
	}
	else std::cout << "ERROR: FAILED TO OPEN FILE TO LOAD";
}

void SaveLoad::EnemyLoad(GameMap* map, std::ifstream& inFile)
{
	int health = 0;
	int attack = 0;
	int x = 0;
	int y = 0;
	EnemyType type;

	inFile.read(reinterpret_cast<char*>(&health), sizeof(health));
	inFile.read(reinterpret_cast<char*>(&attack), sizeof(attack));
	inFile.read(reinterpret_cast<char*>(&x), sizeof(x));
	inFile.read(reinterpret_cast<char*>(&y), sizeof(y));
	inFile.read(reinterpret_cast<char*>(&type), sizeof(type));

	Enemy* enemy = new Enemy(health, attack, x, y, type);
	map->Enemies().push_back(enemy);

}

void SaveLoad::TileLoad(GameMap* map, std::ifstream& inFile)
{
	int x = 0;
	int y = 0;
	EntityType type;

	inFile.read(reinterpret_cast<char*>(&x), sizeof(x));
	inFile.read(reinterpret_cast<char*>(&y), sizeof(y));
	inFile.read(reinterpret_cast<char*>(&type), sizeof(type));

	Tile* tile = new Tile(x, y, type);
	map->Tiles().push_back(tile);
}

void SaveLoad::WipeSaves()
{
	std::ofstream outFile("player.bin", std::ios::binary | std::ios::trunc);
	outFile.close();

	std::ofstream outFile2("map.bin", std::ios::binary | std::ios::trunc);
	outFile2.close();
}

bool SaveLoad::ValidateSave()
{
	bool saveExists;

	std::ifstream inFile("map.bin", std::ios::binary);
	std::ifstream inFile2("player.bin", std::ios::binary);

	if (inFile.is_open() && inFile2.is_open())
	{
		if (inFile.peek() != std::ifstream::traits_type::eof() &&
			inFile2.peek() != std::ifstream::traits_type::eof())
		{
			saveExists = true;
		}
		else saveExists = false;
	}
	else saveExists = false;

	return saveExists;
}
