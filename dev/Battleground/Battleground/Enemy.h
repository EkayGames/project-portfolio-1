#pragma once
#include "Entity.h"
class Enemy :
    public Entity
{
public:

    Enemy(int health, int attack, int x, int y);
    Enemy(int health, int attack, Position pos);
    ~Enemy();
    Enemy(const Enemy& other);
    Enemy& operator=(const Enemy& other);

private:


};

