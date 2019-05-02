#include <iostream>
#include "gtest/gtest.h"
#include <exception>
#include "Game.h"

void Test()
{
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

int main(int argc, char** argv)
{
    try
    {
        Game::RunGame();
        Test();
    }
    catch (const std::exception &exc)
    {
        std::cout << exc.what() << std::endl;
        return -1;
    }

    return 0;
}
