#include "Menus.h"
#include "Helper.h"

// ____              __    __    ___                                                   __            
///\  _`\           /\ \__/\ \__/\_ \                                                 /\ \           
//\ \ \L\ \     __  \ \ ,_\ \ ,_\//\ \      __     __   _ __   ___   __  __    ___    \_\ \    ____  
// \ \  _ <'  /'__`\ \ \ \/\ \ \/ \ \ \   /'__`\ /'_ `\/\`'__\/ __`\/\ \/\ \ /' _ `\  /'_` \  /',__\ 
//  \ \ \L\ \/\ \L\.\_\ \ \_\ \ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \ \ \_\ \/\ \/\ \/\ \L\ \/\__, `\
//   \ \____/\ \__/.\_\\ \__\\ \__\/\____\ \____\ \____ \ \_\\ \____/\ \____/\ \_\ \_\ \___,_\/\____/
//    \/___/  \/__/\/_/ \/__/ \/__/\/____/\/____/\/___L\ \/_/ \/___/  \/___/  \/_/\/_/\/__,_ /\/___/ 
//                                                 /\____/                                           
//                                                 \_/__/       



void Menus::MainMenu(GameMap& map)
{
    bool run = true;
    int menuChoice = 0;
    while (run)
    {
        std::cout << "\033[34m" << R"(
 ____              __    __    ___                                                   __            
/\  _`\           /\ \__/\ \__/\_ \                                                 /\ \           
\ \ \L\ \     __  \ \ ,_\ \ ,_\//\ \      __     __   _ __   ___   __  __    ___    \_\ \    ____  
 \ \  _ <'  /'__`\ \ \ \/\ \ \/ \ \ \   /'__`\ /'_ `\/\`'__\/ __`\/\ \/\ \ /' _ `\  /'_` \  /',__\ 
  \ \ \L\ \/\ \L\.\_\ \ \_\ \ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \ \ \_\ \/\ \/\ \/\ \L\ \/\__, `\
   \ \____/\ \__/.\_\\ \__\\ \__\/\____\ \____\ \____ \ \_\\ \____/\ \____/\ \_\ \_\ \___,_\/\____/
    \/___/  \/__/\/_/ \/__/ \/__/\/____/\/____/\/___L\ \/_/ \/___/  \/___/  \/_/\/_/\/__,_ /\/___/ 
                                                 /\____/                                           
                                                 \_/__/                                                                                                                                                      
)";
        std::cout << "\033[0m";
        std::cout << "1. Begin Game\n2. Settings\n3. Exit\n\nEnter Menu Option: ";
        menuChoice = Helper::GetMenuChoice(1, 3);

        switch (menuChoice)
        {
        case 1: //Start game
            Helper::ClearConsoleWindow();
            MapMenu(map);
            break;
        case 2: //Settings menu
            SettingsMenu(map);
            break;
        case 3: //Exit game
            run = false;
            break;
        }
    }
}

void Menus::SettingsMenu(GameMap& map)
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

void Menus::MapMenu(GameMap& map)
{
    bool run = true;
    map.GenerateMap();
    map.PrintMap();
    std::string userInput;

    while (run)
    {
        std::cout << "Input W A S or D to move up left down or right.\n";

        bool doInput = true;
        while (doInput)
        {
            std::getline(std::cin, userInput);
            const char* charInput = userInput.c_str();
            switch (*charInput)
            {
            case 'w':
            case 'W':
                map.MapPlayer()->Pos()._ypos--;
                doInput = false;

                break;
            case 'a':
            case 'A':
                map.MapPlayer()->Pos()._xpos--;
                doInput = false;

                break;
            case 's':
            case 'S':
                map.MapPlayer()->Pos()._ypos++;
                doInput = false;

                break;

            case 'd':
            case 'D':
                map.MapPlayer()->Pos()._xpos++;
                doInput = false;

                break;
            default:
                std::cout << "Invalid input, Try again: ";
            }
        }

        Helper::ClearConsoleWindow();
        map.PrintMap();

    }
}
