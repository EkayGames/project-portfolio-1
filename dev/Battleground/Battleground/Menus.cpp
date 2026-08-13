#include "Menus.h"

// ____              __    __    ___                                                   __            
///\  _`\           /\ \__/\ \__/\_ \                                                 /\ \           
//\ \ \L\ \     __  \ \ ,_\ \ ,_\//\ \      __     __   _ __   ___   __  __    ___    \_\ \    ____  
// \ \  _ <'  /'__`\ \ \ \/\ \ \/ \ \ \   /'__`\ /'_ `\/\`'__\/ __`\/\ \/\ \ /' _ `\  /'_` \  /',__\ 
//  \ \ \L\ \/\ \L\.\_\ \ \_\ \ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \ \ \_\ \/\ \/\ \/\ \L\ \/\__, `\
//   \ \____/\ \__/.\_\\ \__\\ \__\/\____\ \____\ \____ \ \_\\ \____/\ \____/\ \_\ \_\ \___,_\/\____/
//    \/___/  \/__/\/_/ \/__/ \/__/\/____/\/____/\/___L\ \/_/ \/___/  \/___/  \/_/\/_/\/__,_ /\/___/ 
//                                                 /\____/                                           
//                                                 \_/__/       



void Menus::MainMenu(GameMap* map)
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

            if (map->EnemyCount() < (map->X() * map->Y()) - 1)
            {
                MapMenu(map);
            }
            else
            {
                std::cout << "Error. Enemy count larger than free tile amount.";
            }
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

void Menus::SettingsMenu(GameMap* map)
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
            std::cout << "Enter map width (min 2, max 10): ";
            map->X(Helper::GetMenuChoice(2, 10));
            std::cout << "Enter map height (min 2, max 10): ";
            map->Y(Helper::GetMenuChoice(2, 10));

            Helper::ClearConsoleWindow();
            std::cout << "Map size changed.\n\n";

            break;
        case 2: //Prompt user to change amount of enemies
            std::cout << "Enter number of enemies (Max: " << (map->X() * map->Y()) - 1 << "): ";
            map->EnemyCount(Helper::GetMenuChoice(1, (map->X() * map->Y()) - 1));

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

void Menus::MapMenu(GameMap* map)
{
    bool run = true;
    map->GenerateMap();
    map->PrintMap();
    std::string userInput;

    while (run)
    {
        std::cout << "Input W A S or D to move up left down or right.\n";

        bool doInput = true;
        while (doInput)
        {
            std::getline(std::cin, userInput);

            if (userInput.size() != 1)
            {
                std::cout << "Invalid input, Try again: ";
            }
            else
            {
                switch (userInput[0])
                {
                case 'w':
                case 'W':

                    if (map->MapPlayer()->Pos()._ypos > 0)
                    {
                        map->MapPlayer()->Pos()._ypos--;
                    }
                    doInput = false;

                    break;
                case 'a':
                case 'A':

                    if (map->MapPlayer()->Pos()._xpos > 0)
                    {
                        map->MapPlayer()->Pos()._xpos--;
                    }
                    doInput = false;

                    break;
                case 's':
                case 'S':
                    if (map->MapPlayer()->Pos()._ypos < map->Y() - 1)
                    {
                        map->MapPlayer()->Pos()._ypos++;
                    }

                    doInput = false;

                    break;

                case 'd':
                case 'D':
                    if (map->MapPlayer()->Pos()._xpos < map->X() - 1)
                    {
                        map->MapPlayer()->Pos()._xpos++;
                    }

                    doInput = false;

                    break;
                default:
                    std::cout << "Invalid input, Try again: ";
                }
            }
            
            //Check if player and enemy are on same tile and if so initiate combat
            for (int i = 0; i < map->Enemies().size(); i++)
            {
                if (map->Enemies()[i]->Pos()._xpos == map->MapPlayer()->Pos()._xpos &&
                    map->Enemies()[i]->Pos()._ypos == map->MapPlayer()->Pos()._ypos)
                {
                    Helper::ClearConsoleWindow();
                    CombatMenu(map, i);
                    map->Enemies().erase(map->Enemies().begin() + i);
                    
                }
            }
        }



        Helper::ClearConsoleWindow();
        if (map->MapPlayer()->Health() <= 0)
        {
            map->GameReset();
            return;
        }
        
        if (map->Enemies().size() == 0)
        {
            map->GenerateMap();
            NextFloorScreen();
        }
        
        map->PrintMap();

    }
}

void Menus::CombatMenu(GameMap* map, int enemy)
{
    std::string enemyName;
    switch (map->Enemies()[enemy]->GetEnemyType())
    {
    case EnemyType::WizardShroom:
        enemyName = "Wizard Shroom";
        break;
    case EnemyType::Skeleton:
        enemyName = "Skeleton";
        break;
    case EnemyType::Hippie:
        enemyName = "Hippie";
        break;
    }
    bool doCombat = true;
    int combatChoice = 0;
    int enemyCombatChoice = 0;
    while (doCombat)
    {
        map->Enemies()[enemy]->PrintEnemy();
        std::cout << "\n\n=======================================================\nA " << enemyName << " appears!\n\n";
        if (combatChoice != 0 && enemyCombatChoice != 0)
        {
            Combat::PrintBattleText(combatChoice, enemyCombatChoice, enemyName, map, enemy);
        }
        std::cout << "Enemy health: " << map->Enemies()[enemy]->Health() << "\n";
        std::cout << "Your health: " << map->MapPlayer()->Health() << "\n\n";
        std::cout << "1. Lunge\t\t2. Defend\t\t3. Dash\n\nEnter action choice(1 2 or 3): ";

        combatChoice = Helper::GetMenuChoice(1, 3);
        enemyCombatChoice = Helper::RandomNumberGenerator(1, 3);

        Combat::CalculateDamage(combatChoice, enemyCombatChoice, map, enemy);
        if (map->Enemies()[enemy]->Health() <= 0)
        {
            CombatWinScreen();
            doCombat = false;
        }
        else if (map->MapPlayer()->Health() <= 0)
        {
            LoseScreen();
            doCombat = false;
        }

        Helper::ClearConsoleWindow();


    }
}

void Menus::LoseScreen()
{
    Helper::ClearConsoleWindow();
    std::cout << "YOU LOSE\n\nPress enter to return to main menu...";
    Helper::PauseConsoleWindow();
}

void Menus::CombatWinScreen()
{
    Helper::ClearConsoleWindow();
    std::cout << "YOU WIN!\n\nPress enter to return to map...";
    Helper::PauseConsoleWindow();
}

void Menus::NextFloorScreen()
{
    Helper::ClearConsoleWindow();
    std::cout << "YOU BEAT ALL ENEMIES ON THE FLOOR!\n\nPress enter to enter the next floor...";
    Helper::PauseConsoleWindow();
}

