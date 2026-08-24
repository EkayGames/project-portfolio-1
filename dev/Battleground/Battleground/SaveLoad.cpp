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

	std::ofstream outFile("player.bin", std::ios::binary);


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
//map x, map y, num enemies, num tiles, enemies, tiles,
void SaveLoad::MapSave(GameMap* map)
{
	int x = map->X();
	int y = map->Y();
	int enemyCount = map->EnemyCount();
	int numTiles = map->Tiles().size();

	std::ofstream outFile("map.bin", std::ios::binary);

	if (outFile.is_open())
	{
		outFile.write(reinterpret_cast<const char*>(&x), sizeof(x));
		outFile.write(reinterpret_cast<const char*>(&y), sizeof(y));
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
