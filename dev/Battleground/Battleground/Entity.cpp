#include "Entity.h"

//Rule of three stuff

Entity::Entity(int health, int attack, int x, int y) :
    _health(health), _attack(attack)
{
    _pos._xpos = x;
    _pos._ypos = y;
}

Entity::~Entity()
{

}

Entity::Entity(const Entity& other) : 
    _health(other._health), _attack(other._attack), _pos(other._pos)
{

}

Entity& Entity::operator=(const Entity& other)
{
    if (this == &other)
    {
        return *this;
    }

    _health = other._health;
    _attack = other._attack;
    _pos = other._pos;

    return *this;
}

//Getters

int Entity::Health() const
{
    return _health;
}

int Entity::Attack() const
{
    return _attack;
}

Position& Entity::Pos()
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

