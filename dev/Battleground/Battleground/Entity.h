#pragma once
#include "Position.h"

class Entity
{
public:


	//Getters
	int Health() const;
	int Attack() const;
	Position Pos() const;

	//setters
	void Health(int health);
	void Attack(int attack);
	void Pos(int x, int y);

private:
	int _health = 0;
	int _attack = 0;
	Position _pos;
};

