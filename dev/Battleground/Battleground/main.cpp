#include <iostream>
#include "Helper.h"
#include "GameMap.h"
#include "Menus.h"

int main()
{
    Helper::MemoryLeakDetector(-1);

    srand(time(NULL));

    GameMap* map = new GameMap;

    Menus::MainMenu(map);
}
