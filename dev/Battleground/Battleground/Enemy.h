#pragma once
#include "Entity.h"
#include <iostream>

enum class EnemyType
{
    Error,
    WizardShroom,
    Skeleton,
    Hippie,
    LAST
};

class Enemy :
    public Entity
{
public:

    Enemy(int health, int attack, int x, int y, EnemyType type);
    Enemy(int health, int attack, Position pos, EnemyType type);
    ~Enemy();
    Enemy(const Enemy& other);
    Enemy& operator=(const Enemy& other);

    void PrintEnemy();

    EnemyType GetEnemyType() const;

private:
    EnemyType _enemyType = EnemyType::Error;

};

