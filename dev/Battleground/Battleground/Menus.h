#pragma once
#include "GameMap.h"
#include "Combat.h"
#include "Helper.h"
#include "Powerup.h"
class Menus
{
public:
	static void MainMenu(GameMap* map);
	static void SettingsMenu(GameMap* map);
	static void MapMenu(GameMap* map);
	static void CombatMenu(GameMap* map, int enemy);
	static void NextFloorScreen();
	static void HelpMenu();
	static void PowerUpMenu(GameMap* map);
	static void BestiaryMenu();

private:
	
};

