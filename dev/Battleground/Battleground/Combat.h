#pragma once
#include "GameMap.h"
#include <iostream>
#include <string>
class Combat
{
public:
	static void PrintBattleText(int userChoice, int enemyChoice, std::string enemyName, int damage, GameMap* map);
	static int CalculateDamage(int userChoice, int enemyChoice, GameMap* map, int enemy);
	static int CalculateLunge(int userChoice, int enemyChoice, GameMap* map, int enemy);
	static int CalculateBlock(int userChoice, int enemyChoice, GameMap* map, int enemy);
	static int CalculateDash(int userChoice, int enemyChoice, GameMap* map, int enemy);
	static int CalculateEnemyChoice(GameMap* map, int enemy);

private:
};

