#include "Enemy.h"

Enemy::Enemy(int health, int attack, int x, int y) :
	Entity::Entity(health, attack, x, y)
{

}

Enemy::Enemy(int health, int attack, Position pos) :
	Entity::Entity(health, attack, pos._xpos, pos._ypos)
{
}

Enemy::~Enemy()
{
}

Enemy::Enemy(const Enemy& other) :
    Entity::Entity(other)
{

}

Enemy& Enemy::operator=(const Enemy& other)
{
    if (this == &other)
    {
        return *this;
    }

    Entity::operator=(other);

    return *this;
}