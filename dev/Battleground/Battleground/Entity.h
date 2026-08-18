#pragma once
#include "Position.h"

class Entity
{
public:

	Entity(int health, int attack, int x, int y);
	Entity(int health, int attack);
	~Entity();
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);

	//Getters
	int Health() const;
	int Attack() const;
	Position& Pos();

	//setters
	void Health(int health);
	void Attack(int attack);
	void Pos(int x, int y);

private:
	int _health = 0;
	int _attack = 0;
	Position _pos;
};

