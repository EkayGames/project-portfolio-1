#pragma once
#include "GameMap.h"
class Menus
{
public:
	static void MainMenu(GameMap* map);
	static void SettingsMenu(GameMap* map);
	static void MapMenu(GameMap* map);
	static void CombatMenu(GameMap* map, Enemy* enemy);

private:
	
};

