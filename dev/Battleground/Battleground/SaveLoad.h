#pragma once
#include "GameMap.h"
#include <fstream>
#include <iostream>
class SaveLoad
{
public:
	static void PlayerSave(Player* player);
	static void MapSave(GameMap* map);
	static void EnemySave(Enemy* enemy, std::ofstream& outFile);
	static void TileSave(Tile* tile, std::ofstream& outFile);
	static Player* PlayerLoad();
	static void MapLoad(GameMap* map);
	static void EnemyLoad(GameMap* map, std::ifstream& inFile);
	static void TileLoad(GameMap* map, std::ifstream& inFile);
	static void WipeSaves();
	static bool ValidateSave();
	static void SettingsSave(GameMap* map);
	static void SettingsLoad(GameMap* map);
private:

};

