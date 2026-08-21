#pragma once
#include <iostream>
#include "Helper.h"

class Player;

enum class Power
{
	HealthUp = 1,
	DamageUp,
	LungeDamage,
	BlockDamage,
	DashDamage,
	HealRate,
	Count,
};

class Powerup
{
public:

	Powerup(int pow);
	Powerup(Power pow);
	~Powerup();
	Powerup(const Powerup& other);
	Powerup& operator=(const Powerup& other);

	void PrintPower();
	void RerollDuplicates(Player* player);
	void RerollDuplicates(Powerup* dupe, Player* player);
	void RerollDuplicates(Powerup* dupe, Powerup* dupe2, Player* player);

	Power GetPower() const;

	void SetPower(int pow);

private:
	Power _power;
};