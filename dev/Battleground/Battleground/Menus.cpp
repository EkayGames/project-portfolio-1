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
        std::cout << "1. Begin Game\n2. Settings\n3. Help\n4. Bestiary\n5. Exit\n\nEnter Menu Option: ";
        menuChoice = Helper::GetMenuChoice(1, 5);

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
        case 3:
            HelpMenu();
            break;
        case 4: //Exit game
            BestiaryMenu();
            break;
        case 5:
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
    map->MapPlayer(new Player(10, 5));
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

            //Get user input for direction
            if (userInput.size() != 1)
            {
                std::cout << "Invalid input. Please use W A S or D: ";
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
                    std::cout << "Invalid input. Please use W A S or D: ";
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
                    
                    break;
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
            PowerUpMenu(map);
        }
        
        map->PrintMap();

    }
}

void Menus::CombatMenu(GameMap* map, int enemy)
{
    std::string enemyName;
    switch (map->Enemies()[enemy]->GetEnemyType()) //Store enemy name for combat text
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
    int damage = 0;
    while (doCombat)
    {
        //Print menu
        map->Enemies()[enemy]->PrintEnemy();
        std::cout << "\n\n=======================================================\nA " << enemyName << " appears!\n\n";
        if (combatChoice != 0 && enemyCombatChoice != 0)
        {
            Combat::PrintBattleText(combatChoice, enemyCombatChoice, enemyName, damage, map);
        }
        std::cout << "\nEnemy health: " << map->Enemies()[enemy]->Health() << "\n";
        std::cout << "Your health: " << map->MapPlayer()->Health() << "/" <<  map->MapPlayer()->MaxHealth() << "\n\n";

        if (map->Enemies()[enemy]->Health() > 0 && map->MapPlayer()->Health() > 0)
        {
            std::cout << "1. Lunge\t\t2. Defend\t\t3. Dash\n\nEnter action choice(1 2 or 3): ";
        }

        //Win if enemy health is 0, lose if player health is 0
        if (map->Enemies()[enemy]->Health() <= 0)
        {
            std::cout << "Press enter to return to map...";
            Helper::PauseConsoleWindow();
            doCombat = false;
        }
        else if (map->MapPlayer()->Health() <= 0)
        {
            std::cout << "YOU LOSE!\n";
            std::cout << "Press enter to return to main menu...";
            Helper::PauseConsoleWindow();
            doCombat = false;
        }

        //Get user input and calculate damage
        if (map->Enemies()[enemy]->Health() > 0 && map->MapPlayer()->Health() > 0)
        {
            combatChoice = Helper::GetMenuChoice(1, 3);
            enemyCombatChoice = Combat::CalculateEnemyChoice(map, enemy);
            damage = Combat::CalculateDamage(combatChoice, enemyCombatChoice, map, enemy);
        }





        Helper::ClearConsoleWindow();


    }
}

void Menus::NextFloorScreen()
{
    Helper::ClearConsoleWindow();
    std::cout << "YOU BEAT ALL ENEMIES ON THE FLOOR!\n\nPress enter to enter the next floor...";
    Helper::PauseConsoleWindow();
}

void Menus::HelpMenu()
{
    Helper::ClearConsoleWindow();
    std::cout << "Instructions\n===============\nDefeat all enemies on the map to move to the next one!\n";
    std::cout << "Enter W A S D to move around the map and reach enemies!\n";
    std::cout << "Lunge beats block, block beats dash, and dash beats lunge!\n\nPress any button to return to the main menu...";

    Helper::PauseConsoleWindow();
    Helper::ClearConsoleWindow();
}

void Menus::PowerUpMenu(GameMap* map)
{
    //Generate powerup option 1
    Powerup* pow1 = new Powerup(Helper::RandomNumberGenerator(1, static_cast<int>(Power::Count) - 1));
    //Generate powerup option 2
    Powerup* pow2 = new Powerup(Helper::RandomNumberGenerator(1, static_cast<int>(Power::Count) - 1));
    if (pow2->GetPower() == pow1->GetPower())
    {
        pow2->RerollDuplicates(pow1);
    }
    //Generate powerup option 3
    Powerup* pow3 = new Powerup(Helper::RandomNumberGenerator(1, static_cast<int>(Power::Count) - 1));
    if (pow3->GetPower() == pow1->GetPower() ||
        pow3->GetPower() == pow2->GetPower())
    {
        pow3->RerollDuplicates(pow1, pow2);
    }

    map->MapPlayer()->Health(map->MapPlayer()->Health() + 5); //Heal 5 health
    if (map->MapPlayer()->Health() > map->MapPlayer()->MaxHealth()) //If player health goes higher than max health, set health to max health
    {
        map->MapPlayer()->Health(map->MapPlayer()->MaxHealth());
    }

    //Print options
    Helper::ClearConsoleWindow();
    std::cout << "YOU BEAT ALL ENEMIES ON THE FLOOR!\nYOU HEALED 5 HEALTH!\nSELECT A POWERUP!\n\n";
    std::cout << "1. ";
    pow1->PrintPower();
    std::cout << "2. ";
    pow2->PrintPower();
    std::cout << "3. ";
    pow3->PrintPower();
    //Get choice
    std::cout << "\nInput Power Choice: ";
    int powChoice = Helper::GetMenuChoice(1, 3);
    switch (powChoice)
    {
    case 1:
        map->MapPlayer()->ApplyPower(pow1);
        break;
    case 2:
        map->MapPlayer()->ApplyPower(pow2);
        break;
    case 3:
        map->MapPlayer()->ApplyPower(pow3);
        break;
    }

    Helper::ClearConsoleWindow();
}

void Menus::BestiaryMenu()
{
    bool run = true;
    Enemy enemy = Enemy(0, 0, 0, 0, EnemyType::Error);
    int menuChoice = 0;
    while (run)
    {
        Helper::ClearConsoleWindow();
        std::cout << R"(
 ____                    __                                     
/\  _`\                 /\ \__  __                              
\ \ \L\ \     __    ____\ \ ,_\/\_\     __     _ __   __  __    
 \ \  _ <'  /'__`\ /',__\\ \ \/\/\ \  /'__`\  /\`'__\/\ \/\ \   
  \ \ \L\ \/\  __//\__, `\\ \ \_\ \ \/\ \L\.\_\ \ \/ \ \ \_\ \  
   \ \____/\ \____\/\____/ \ \__\\ \_\ \__/.\_\\ \_\  \/`____ \ 
    \/___/  \/____/\/___/   \/__/ \/_/\/__/\/_/ \/_/   `/___/> \
                                                          /\___/
                                                          \/__/ 
)";


        std::cout << "\n\n1. Wizard Shroom\n2. Skeleton\n3. Hippie\n4. Exit\n\n";
        std::cout << "Enter Menu Option: ";
        menuChoice = Helper::GetMenuChoice(1, 4);
        Helper::ClearConsoleWindow();
        switch (menuChoice)
        {
        case 1:
            enemy.SetEnemyType(EnemyType::WizardShroom);
            enemy.PrintEnemy();
            std::cout << "\n=======================================================\n";
            std::cout << "WIZARD SHROOM\nHealth: 5\nAttack: 5\nAttack Preference: Lunge\n\n";
            std::cout << "Press enter to return to bestiary menu...";
            Helper::PauseConsoleWindow();
            break;
        case 2:
            enemy.SetEnemyType(EnemyType::Skeleton);
            enemy.PrintEnemy();
            std::cout << "\n=======================================================\n";
            std::cout << "SKELETON\nHealth: 10\nAttack: 3\nAttack Preference: Lunge and Block\n\n";
            std::cout << "Press enter to return to bestiary menu...";
            Helper::PauseConsoleWindow();
            break;
        case 3:
            enemy.SetEnemyType(EnemyType::Hippie);
            enemy.PrintEnemy();
            std::cout << "\n=======================================================\n";
            std::cout << "HIPPIE\nHealth: 25\nAttack: 1\nAttack Preference: Dash\n\n";
            std::cout << "Press enter to return to bestiary menu...";
            Helper::PauseConsoleWindow();
            break;
        case 4:
            run = false;
            break;
        }
    }
}

