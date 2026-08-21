#include "Combat.h"

//Display text based on combat choices
void Combat::PrintBattleText(int userChoice, int enemyChoice, std::string enemyName, int damage, GameMap* map)
{
    if (userChoice == 1 && enemyChoice == 1)
    {
        std::cout << "You both lunged and clashed!";
    }
    else if (userChoice == 1 && enemyChoice == 2)
    {
        std::cout << "You lunged and broke " << enemyName << "'s guard dealing " << damage << " damage!";
    }
    else if (userChoice == 1 && enemyChoice == 3)
    {
        std::cout << enemyName << " dodged your attack and dealt " << damage << " damage!";
    }
    else if (userChoice == 2 && enemyChoice == 1)
    {
        std::cout << enemyName << " broke your guard, dealing " << damage << " damage!";
    }
    else if (userChoice == 2 && enemyChoice == 2)
    {
        std::cout << "You both stood there blocking for a while...";
    }
    else if (userChoice == 2 && enemyChoice == 3)
    {
        std::cout << "You blocked " << enemyName << "'s attack and countered, dealing " << damage << " damage!";
    }
    else if (userChoice == 3 && enemyChoice == 1)
    {
        std::cout << "You dodged " << enemyName << "'s attack and countered, dealing " << damage << " damage!";
    }
    else if (userChoice == 3 && enemyChoice == 2)
    {
        std::cout << enemyName << " blocked your attack and countered, dealing " << damage << " damage!";
    }
    else if (userChoice == 3 && enemyChoice == 3)
    {
        bool hasPower = false;
        for (auto& i : map->MapPlayer()->Powers())
        {
            if (i.GetPower() == Power::DashDamage)
            {
                std::cout << "You grazed " << enemyName << ", dealing " << damage << " damage!";
                hasPower = true;
                break;
            }
        }
        if (hasPower == false)
        {
            std::cout << "You both swung at each other and missed!";
        }
    }
    std::cout << "\n";
}

//calculate damage taken from combat turn
int Combat::CalculateDamage(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    int damage = 0;
    switch (userChoice)
    {
    case 1:
        damage = CalculateLunge(userChoice, enemyChoice, map, enemy);
        break;
    case 2:
        damage = CalculateBlock(userChoice, enemyChoice, map, enemy);
        break;
    case 3:
        damage = CalculateDash(userChoice, enemyChoice, map, enemy);
        break;
    }
    return damage;
}

int Combat::CalculateLunge(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    int damage = 0;
    switch (enemyChoice)
    {
    case 2:

        for (auto& i : map->MapPlayer()->Powers())
        {
            if (i.GetPower() == Power::LungeDamage)
            {
                map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - (map->MapPlayer()->Attack() * 2));
                damage = map->MapPlayer()->Attack() * 2;
                break;
            }
        }

        if (damage != map->MapPlayer()->Attack() * 2)
        {
            map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - map->MapPlayer()->Attack());
            damage = map->MapPlayer()->Attack();
        }

        break;
    case 3:
        map->MapPlayer()->Health(map->MapPlayer()->Health() - map->Enemies()[enemy]->Attack());
        damage = map->Enemies()[enemy]->Attack();
        break;
    }
    return damage;
}

int Combat::CalculateBlock(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    int damage = 0;
    switch (enemyChoice)
    {
    case 3:
        map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - map->MapPlayer()->Attack());
        damage = map->MapPlayer()->Attack();
        break;
    case 1:
        map->MapPlayer()->Health(map->MapPlayer()->Health() - map->Enemies()[enemy]->Attack());
        damage = map->Enemies()[enemy]->Attack();
        break;
    }
    return damage;
}

int Combat::CalculateDash(int userChoice, int enemyChoice, GameMap* map, int enemy)
{
    int damage = 0;
    switch (enemyChoice)
    {
    case 1:
        map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - map->MapPlayer()->Attack());
        damage = map->MapPlayer()->Attack();
        break;
    case 2:
        map->MapPlayer()->Health(map->MapPlayer()->Health() - map->Enemies()[enemy]->Attack());
        damage = map->Enemies()[enemy]->Attack();
        break;
    case 3:
        for (auto& i : map->MapPlayer()->Powers())
        {
            if (i.GetPower() == Power::DashDamage)
            {
                map->Enemies()[enemy]->Health(map->Enemies()[enemy]->Health() - (map->MapPlayer()->Attack() / 2));
                damage = map->MapPlayer()->Attack() / 2;
                break;
            }
        }
        break;
    }
    return damage;
}

int Combat::CalculateEnemyChoice(GameMap* map, int enemy)
{
    int choice = 0;
    int rng = 0;
    switch (map->Enemies()[enemy]->GetEnemyType())
    {
    case EnemyType::WizardShroom: //Wizard shroom behavior
        rng = Helper::RandomNumberGenerator(1, 5);
        switch (rng)
        {
        case 1:
        case 2:
        case 3:
            choice = 1;
            break;
        case 4:
            choice = 2;
            break;
        case 5:
            choice = 3;
            break;
        }
        break;
    case EnemyType::Skeleton: //Skeleton behavior
        rng = Helper::RandomNumberGenerator(1, 5);
        switch (rng)
        {
        case 1:
        case 2:
            choice = 1;
            break;
        case 3:
        case 4:
            choice = 2;
            break;
        case 5:
            choice = 3;
            break;
        }
        break;

    case EnemyType::Hippie: //Hippie behavior 
        rng = Helper::RandomNumberGenerator(1, 6);
        switch (rng)
        {
        case 1:
            choice = 1;
            break;
        case 2:
            choice = 2;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            choice = 3;
            break;
        }
        break;
    }
    return choice;
}
