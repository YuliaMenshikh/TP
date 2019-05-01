#include <iostream>
#include <vector>
#include <memory>

#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "YlayaSingleton.h"
#include "DuncanSingleton.h"
#include "gtest/gtest.h"
#include "Exceptions.h"
#include "Squad.h"
#include "SimpleStrategy.h"

/*Unit::Ptr TestSquad()
{
    UnitFactory::Ptr factory = std::make_shared<DungeonFactory>();
    std::shared_ptr<Squad> squad(new Squad("1 squad"));
    squad->AddUnit(factory->CreateUnit(1), Position(1,2));
    squad->AddUnit(factory->CreateUnit(3), Position(2,3));

    return squad;
}*/

void TestBattleField()
{
    //return;
    UnitFactory::Ptr factory = std::make_shared<DungeonFactory>();
    Position position1(6, 6);
    //Position position2(6, 6);
    factory->CreateHero()->AddUnit(factory->CreateUnit(1), position1);
    //factory->CreateHero()->AddUnit(factory->CreateUnit(2), position2);
}

void TestGetClosestUnits()
{
    UnitFactory::Ptr factory1 = std::make_shared<DungeonFactory>();
    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();
    Hero::Ptr hero1 = factory1->CreateHero();
    Hero::Ptr hero2 = factory2->CreateHero();
    hero1->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonMinotaur), Position(1, 1));
    hero1->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonHydra), Position(3, 3));
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPeasant), Position(5, 6));
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenFootman), Position(2, 2));
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);

    for (int i = 0; i < 10; ++i)
    {
        strategy->MakeStep(hero1, hero2);
        if (!hero2->HasUnits())
        {
            std::cout << "Армия героя " << hero2->GetName() << " уничтожена" << std::endl;
            break;
        }

        strategy->MakeStep(hero2, hero1);
        if (!hero1->HasUnits())
        {
            std::cout << "Армия героя " << hero1->GetName() << " уничтожена" << std::endl;
            break;
        }

    }
}

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
    try
    {
        Test();
        TestBattleField();
        TestGetClosestUnits();
        //ClientCode();
        //TestSquad();
    }
    catch (const std::exception &exc)
    {
        std::cout << exc.what() << std::endl;
        return -1;
    }

    return 0;
}
