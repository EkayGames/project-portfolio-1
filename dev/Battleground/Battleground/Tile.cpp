#include "Tile.h"
#include <iostream>



//=====
//|   |
//=====

void Tile::Print() const
{
    if (_entityType == "Empty")
    {
        std::cout << "|   |";
    }
}


// Getters

Position Tile::Pos() const
{
    return _pos;
}

std::string Tile::EntityType() const
{
    return _entityType;
}

//Setters 

void Tile::Pos(int x, int y)
{
    _pos._xpos = x;
    _pos._ypos = y;
}

void Tile::EntityType(std::string& type)
{
    _entityType = type;
}
