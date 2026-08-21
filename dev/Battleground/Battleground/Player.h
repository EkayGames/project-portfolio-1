#pragma once
#include "Entity.h"
#include "Powerup.h"
#include <vector>
class Player :
    public Entity
{
public:

    Player(int health, int attack, int x, int y);
    Player(int health, int attack, Position pos);
    Player(int health, int attack);
    ~Player();
    Player(const Player& other);
    Player& operator=(const Player& other);

    void ApplyPower(Power pow);

    void MaxHealth(int max);
    void HealRate(int heal);

    int MaxHealth() const;
    int HealRate() const;
    const std::vector<Power>& Powers() const;

private:
    int _maxHealth = 10;
    std::vector<Power> _powers;
    int _healRate = 5;
};

