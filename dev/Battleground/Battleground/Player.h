#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:

    Player(int health, int attack, int x, int y);
    Player(int health, int attack, Position pos);
    ~Player();
    Player(const Player& other);
    Player& operator=(const Player& other);


private:

};

