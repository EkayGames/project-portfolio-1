#pragma once
#include <iostream>
#include "Helper.h"
enum class Power
{
	HealthUp = 1,
	DamageUp,
	LungeDamage,
	BlockDamage,
	DashDamage,
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
	void RerollDuplicates(Powerup* dupe);
	void RerollDuplicates(Powerup* dupe, Powerup* dupe2);

	Power GetPower() const;

	void SetPower(int pow);

private:
	Power _power;
};