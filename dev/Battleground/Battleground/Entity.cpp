#include "Entity.h"

//Getters

int Entity::Health() const
{
    return _health;
}

int Entity::Attack() const
{
    return _attack;
}

Position Entity::Pos() const
{
    return _pos;
}

//Setters

void Entity::Health(int health)
{
    _health = health;
}

void Entity::Attack(int attack)
{
    _attack = attack;
}

void Entity::Pos(int x, int y)
{
    _pos._xpos = x;
    _pos._ypos = y;
}

