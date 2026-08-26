#include "Tile.h"
#include <iostream>



//=====
//|   |
//=====

//Print the correct center depending on the entity type
void Tile::Print() const
{
    switch (_entityType)
    {
    case EntityType::Empty:
        std::cout << "|   |";
        break;
    case EntityType::Player:
        std::cout << "|";
        Helper::PrintText(Color::BLUE, BackgroundColor::WHITE, " P ");
        std::cout << "|";
        break;
    case EntityType::Enemy:
        std::cout << "|";
        Helper::PrintText(Color::WHITE, BackgroundColor::RED, " E ");
        std::cout << "|";
        break;
    }
}



// Getters

Position Tile::Pos() const
{
    return _pos;
}

EntityType Tile::GetEntityType() const
{
    return _entityType;
}

//Setters 

void Tile::Pos(int x, int y)
{
    _pos._xpos = x;
    _pos._ypos = y;
}

void Tile::SetEntityType(EntityType type)
{
    _entityType = type;
}
