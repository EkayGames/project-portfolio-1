#pragma once
#include "GameMap.h"
#include <iostream>
#include <string>
class Combat
{
public:
	static void PrintBattleText(int userChoice, int enemyChoice, std::string enemyName, GameMap* map, int enemy);
	static void CalculateDamage(int userChoice, int enemyChoice, GameMap* map, int enemy);
	static void CalculateLunge(int userChoice, int enemyChoice, GameMap* map, int enemy);
	static void CalculateBlock(int userChoice, int enemyChoice, GameMap* map, int enemy);
	static void CalculateDash(int userChoice, int enemyChoice, GameMap* map, int enemy);

private:
};

