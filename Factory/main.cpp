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

void ClientCode()
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

    std::shared_ptr<Strategy> strategy(new Strategy1);
    Hero::Ptr hero = factory->CreateHero(strategy);

    int unitId = 0;
    int x, y;

    while (true)
    {
        std::cout << std::endl;
        std::cout << "Do you want to create a squad?" << std::endl << "0 - No" << std::endl << "1 - Yes" << std::endl;
        bool flag;
        std::cin >> flag;
        if (flag == 0)
            break;
        else if (flag == 1)
        {
            std::cout << "Enter the name: ";
            std::string name;
            std::cin >> name;
            std::shared_ptr<Squad> squad(new Squad(name));
            std::cout << std::endl;
            while (true)
            {
                std::cout << std::endl;
                std::cout << "Select " << factory->GetName() << " unit for the squad:" << std::endl;
                std::cout << "0 - Select complete" << std::endl;
                for (size_t i = 0; i < availableUnits.size(); ++i)
                {
                    std::cout << availableUnits[i].first << " - " << availableUnits[i].second << std::endl;
                }

                std::cin >> unitId;
                if (unitId == 0)
                {
                    try
                    {
                        std::cout << "Set positon: ";

                        std::cin >> x >> y;
                        hero->AddUnit(squad, Position(x, y));
                    }
                    catch (const InvalidUnitIdException &)
                    {
                        std::cout << "Invalid Select" << std::endl;
                    }
                    break;
                }

                try
                {
                    squad->AddUnit(factory->CreateUnit(unitId));
                }
                catch (const InvalidUnitIdException&)
                {
                    std::cout << "Invalid Select" << std::endl;
                }
            }
        }
    }

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

        std::cout << "Set positon: ";

        std::cin >> x >> y;

        try
        {
            hero->AddUnit(factory->CreateUnit(unitId), Position(x, y));
        }
        catch (const InvalidUnitIdException&)
        {
            std::cout << "Invalid Select" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Hero: " << hero->GetName() << std::endl;
    std::cout << factory->GetName() << " units:" << std::endl;
    //std::vector<Unit::Ptr> units;

    UnitInfo::CollectionPtr collection;

    collection = hero->GetUnits();
    for (auto unit : *collection)
    {
        if (!unit->GetUnit()->IsComposite())
            std::cout << unit->GetUnit()->GetName() << " (" << unit->GetPosition().GetX() << ", " << unit->GetPosition().GetY() << ")" << std::endl << std::endl;
        else
        {
            std::cout << "Squad " << unit->GetUnit()->GetName() << " (" << unit->GetPosition().GetX() << ", " << unit->GetPosition().GetY() << "):" << std::endl;
            Unit::CollectionPtr unitsInCollection = unit->GetUnit()->GetCompositeUnit()->GetUnits();
            for (auto _unit : *unitsInCollection)
                std::cout << '\t' << "- " << _unit->GetName() << std::endl;
        }
    }

    Hero::Ptr hero2;

    if (factoryId == HeavenFactoryId)
        hero2 = Game::ConstructYalayaArmy();
    else
        hero2 = Game::ConstructDuncanArmy();

    Game::RunBattle(hero, hero2);
}


void Test()
{
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}

int main(int argc, char** argv)
{
    try
    {
        //ClientCode();
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
