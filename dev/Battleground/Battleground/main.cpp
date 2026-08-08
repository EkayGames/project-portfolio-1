#include <iostream>
#include "Helper.h"
#include "GameMap.h"
#include "Menus.h"

int main()
{
    srand(time(NULL));
    bool run = true;
    GameMap map;

    Menus::MainMenu(map);
}
