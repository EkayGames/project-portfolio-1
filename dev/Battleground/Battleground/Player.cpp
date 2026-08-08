#include "Player.h"

Player::Player(int health, int attack, int x, int y) :
	Entity::Entity(health, attack, x, y)
{

}

Player::Player(int health, int attack, Position pos) :
	Entity::Entity(health, attack, pos._xpos, pos._ypos)
{

}

Player::~Player()
{
}

Player::Player(const Player& other) :
	Entity::Entity(other)
{

}

Player& Player::operator=(const Player& other)
{
    if (this == &other)
    {
        return *this;
    }

    Entity::operator=(other);

    return *this;
}
