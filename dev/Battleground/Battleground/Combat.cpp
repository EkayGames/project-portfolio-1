#include "Combat.h"

//Display text based on combat choices
void Combat::PrintBattleText(int userChoice, int enemyChoice, std::string enemyName, GameMap* map, int enemy)
{
    if (userChoice == 1 && enemyChoice == 1)
    {
        std::cout << "You both lunged and clashed!";
    }
    else if (userChoice == 1 && enemyChoice == 2)
    {
        std::cout << "You lunged and broke" << enemyName << "'s guard dealing " << map->MapPlayer()->Attack() << " damage!";
    }
    else if (userChoice == 1 && enemyChoice == 3)
    {
        std::cout << enemyName << " dodged your attack and dealt " << map->Enemies()[enemy]->Attack() << " damage!";
    }
    else if (userChoice == 2 && enemyChoice == 1)
    {
        std::cout << enemyName << " broke your guard, dealing " << map->Enemies()[enemy]->Attack() << " damage!";
    }
    else if (userChoice == 2 && enemyChoice == 2)
    {
        std::cout << "You both stood there blocking for a while...";
    }
    else if (userChoice == 2 && enemyChoice == 3)
    {
        std::cout << "You blocked " << enemyName << "'s attack and countered, dealing " << map->MapPlayer()->Attack() << " damage!";
    }
    else if (userChoice == 3 && enemyChoice == 1)
    {
        std::cout << "You dodged " << enemyName << "'s attack and countered, dealing " << map->MapPlayer()->Attack() << " damage!";
    }
    else if (userChoice == 3 && enemyChoice == 2)
    {
        std::cout << enemyName << " blocked your attack and countered, dealing " << map->Enemies()[enemy]->Attack() << " damage!";
    }
    else if (userChoice == 3 && enemyChoice == 3)
    {
        std::cout << "You both swung at each other and missed!";
    }
    std::cout << "\n";
}

//calculate damage taken from combat turn
void Combat::CalculateDamage(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    switch (userChoice)
    {
    case 1:
        CalculateLunge(userChoice, enemyChoice, map, enemy);
        break;
    case 2:
        CalculateBlock(userChoice, enemyChoice, map, enemy);
        break;
    case 3:
        CalculateDash(userChoice, enemyChoice, map, enemy);
        break;
    }
}

void Combat::CalculateLunge(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    switch (enemyChoice)
    {
    case 2:
        map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - map->MapPlayer()->Attack());
        break;
    case 3:
        map->MapPlayer()->Health(map->MapPlayer()->Health() - map->Enemies()[enemy]->Attack());
        break;
    }
}

void Combat::CalculateBlock(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    switch (enemyChoice)
    {
    case 3:
        map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - map->MapPlayer()->Attack());
        break;
    case 1:
        map->MapPlayer()->Health(map->MapPlayer()->Health() - map->Enemies()[enemy]->Attack());
        break;
    }
}

void Combat::CalculateDash(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    switch (enemyChoice)
    {
    case 1:
        map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - map->MapPlayer()->Attack());
        break;
    case 2:
        map->MapPlayer()->Health(map->MapPlayer()->Health() - map->Enemies()[enemy]->Attack());
        break;
    }
}
