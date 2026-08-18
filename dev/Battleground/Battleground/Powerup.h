#pragma once
#include <iostream>
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

	Power GetPower() const;

	void SetPower(int pow);

private:
	Power _power;
};