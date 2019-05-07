#include <iostream>
#include "gtest/gtest.h"
#include <exception>
#include "Game.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "Exceptions.h"
#include "Hero.h"
#include "SimpleStrategy.h"
#include "Strategy1.h"
#include "Squad.h"
#include "HeroGenerator.h"
#include "BattleField.h"

void Test()
{
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

void Run()
{
    while (true)
    {
        std::cout << "Select game mode:" << std::endl;
        std::cout << "0 - Close the game" << std::endl << "1 - Demonstration" << std::endl << "2 - Run Game" << std::endl << "3 - Run Tests" << std::endl;
        int GameMode;
        std::cin >> GameMode;
        if (GameMode == 0)
            break;

        else if (GameMode == 1)
            Game::RunGame();

        else if (GameMode == 2)
            Game::ClientCode();

        else if(GameMode == 3)
            Test();

        else
            std::cout << "Invalid select" << std::endl;
    }
}

int main(int argc, char** argv)
{
    try
    {
        bool runTest = false;
        if (argc == 2)
        {
            if (!strcmp(argv[1], "-test"))
            {
                runTest = true;
            }
        }

        if (runTest)
        {
            Test();
        }
        else
        {
            Run();
        }
    }
    catch (const std::exception &exc)
    {
        std::cout << exc.what() << std::endl;
        return -1;
    }

    return 0;
}
