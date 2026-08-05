#include <iostream>
#include "Helper.h"
#include "GameMap.h"

void SettingsMenu(GameMap& map);

int main()
{
    bool run = true;
    int menuChoice = 0;
    GameMap map;
    while (run)
    {
        std::cout << "1. Begin Game\n2. Settings\n3. Exit\n\nEnter Menu Option: ";
        menuChoice = Helper::GetMenuChoice(1, 3);

        switch (menuChoice)
        {
        case 1:
            Helper::ClearConsoleWindow();
            map.GenerateMap();
            map.PrintMap();
            break;
        case 2:
            SettingsMenu(map);
            break;
        case 3:
            run = false;
            break;
        }
    }
}

void SettingsMenu(GameMap& map)
{
    bool run = true;
    int menuChoice = 0;
    Helper::ClearConsoleWindow();

    while (run)
    {
        std::cout << "SETTINGS\n";
        std::cout << "1. Map Size\n2. Enemy Count\n3. Exit\n\n Enter Menu Option: ";
        menuChoice = Helper::GetMenuChoice(1, 3);

        switch (menuChoice)
        {
        case 1: //Prompt user to change map width and height then store values.
            std::cout << "Enter map width (max 10): ";
            map.X(Helper::GetMenuChoice(1, 10));
            std::cout << "Enter map height (max 10): ";
            map.Y(Helper::GetMenuChoice(1, 10));

            Helper::ClearConsoleWindow();
            std::cout << "Map size changed.\n\n";

            break;
        case 2: //Prompt user to change amount of enemies
            std::cout << "Enter number of enemies: ";
            map.EnemyCount(Helper::GetMenuChoice(1, 3));

            Helper::ClearConsoleWindow();
            std::cout << "Enemy count changed.\n\n";
            break;
        case 3: //Exit settings menu back to main
            Helper::ClearConsoleWindow();
            run = false;
            break;
        }
    }
}
