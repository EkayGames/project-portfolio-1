#include "Player.h"

Player::Player(int health, int attack, int x, int y) :
	Entity::Entity(health, attack, x, y)
{

}

Player::Player(int health, int attack, Position pos) :
	Entity::Entity(health, attack, pos._xpos, pos._ypos)
{

}

Player::Player(int health, int attack) :
    Entity::Entity(health, attack)
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

//Increase player stats, or add powerup based on power input
void Player::ApplyPower(Powerup* pow)
{
    switch (pow->GetPower())
    {
    case Power::HealthUp:
        _maxHealth = _maxHealth + 5;
        Health(Health() + 5);
        if (Health() > _maxHealth)
        {
            Health(_maxHealth);
        }
        break;
    case Power::DamageUp:
        Attack(Attack() + 1);
        break;
    case Power::LungeDamage:
        _powers.push_back(Power::LungeDamage);
        break;
    case Power::BlockDamage:
        _powers.push_back(Power::BlockDamage);
        break;
    case Power::DashDamage:
        _powers.push_back(Power::DashDamage);
        break;
    }
}

void Player::MaxHealth(int max)
{
    _maxHealth = max;
}

int Player::MaxHealth() const
{
    return _maxHealth;
}

std::vector<Powerup> Player::Powers() const
{
    return _powers;
}
