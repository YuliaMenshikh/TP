#include <iostream>
#include <vector>
#include <memory>

#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "YlayaHero.h"
#include "DuncanHero.h"
#include "gtest/gtest.h"
#include "Exceptions.h"
#include "Squad.h"
#include "SimpleStrategy.h"
#include "Game.h"

/*void ClientCode()
{
    const int DungeonfactoryId = 1;
    const int HeavenFactoryId = 2;

    std::cout << "Select team:" << std::endl;
    std::cout << DungeonfactoryId << ": " << DungeonFactory::name() << std::endl;
    std::cout << HeavenFactoryId << ": " << HeavenFactory::name() << std::endl;

    int factoryId = 0;
    std::cin >> factoryId;
    UnitFactory::Ptr factory;
    switch (factoryId)
    {
        case DungeonfactoryId:
            factory = std::make_shared<DungeonFactory>();
            break;
        case HeavenFactoryId:
            factory = std::make_shared<HeavenFactory>();
            break;
        default:
            throw InvalidFactoryIdException();
    }

    UnitFactory::UnitItems availableUnits;
    factory->GetAvailableUnits(availableUnits);

    int unitId = 0;
    while (true)
    {
        std::cout << std::endl;
        std::cout << "Select " << factory->GetName() << " unit:" << std::endl;
        std::cout << "0 - Select complete" << std::endl;
        for (size_t i = 0; i < availableUnits.size(); ++i)
        {
            std::cout << availableUnits[i].first << " - " << availableUnits[i].second << std::endl;
        }

        std::cin >> unitId;
        if (unitId == 0)
            break;

        try
        {
            Position position(0, 0);
            factory->GetHero().AddUnit(factory->CreateUnit(unitId), position);
        }
        catch (const InvalidUnitIdException&)
        {
            std::cout << "Invalid Select" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Hero: " << factory->GetHero().GetName() << std::endl;
    std::cout << factory->GetName() << " units:" << std::endl;
    Unit::Collection units;
    factory->GetHero().GetUnits(units);
    for (size_t i = 0; i < units.size(); ++i)
    {
        std::cout << units[i].first->GetName() << "  power(" << units[i].first->GetPower() << ")" << std::endl;
    }
}*/

void Test()
{
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

int main(int argc, char** argv)
{
    Game::RunGame();
    try
    {
        Test();
        //ClientCode();
    }
    catch (const std::exception &exc)
    {
        std::cout << exc.what() << std::endl;
        return -1;
    }

    return 0;
}
