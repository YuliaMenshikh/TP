#include "Game.h"
#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "SimpleStrategy.h"
#include "Strategy1.h"
#include "Squad.h"
#include "DoubleHealthUnitDecorator.h"
#include "Logger.h"
#include "HeroGenerator.h"
#include "BattleField.h"
#include "Exceptions.h"
#include <random>
#include <sstream>

void  Game::RunGame()
{
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);
    UnitFactory::Ptr factory1 = std::make_shared<DungeonFactory>();
    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();

    std::random_device rd;
    std::default_random_engine generator( rd() );
    std::uniform_int_distribution<int> distributionOfPower(30, 100);

    int Power = distributionOfPower(generator);


    Hero::Ptr hero1 = HeroGenerator::GenerateArmyWithPower(factory1, Power);
    Hero::Ptr hero2 = HeroGenerator::GenerateArmyWithPower(factory2, Power);

    Logger::getInstance().Write("\n1 army:\n");
    DumpArmy(factory1, hero1);

    Logger::getInstance().Write("\n2 army:\n");
    DumpArmy(factory2, hero2);

    Logger::getInstance().Write("\n");

    RunBattle(hero1, hero2);
}

void Game::RunBattle(Hero::Ptr hero1, Hero::Ptr hero2)
{
    while (true)
    {
        hero1->MakeStep(*hero2);
        if (!hero2->HasUnits())
        {
            Logger::getInstance().Write(hero2->GetName() + "'s army destroyed\n");
            Logger::getInstance().Write(hero1->GetName() + " won\n\n");
            break;
        }

        hero2->MakeStep(*hero1);
        if (!hero1->HasUnits())
        {
            Logger::getInstance().Write(hero1->GetName() + "'s army destroyed\n");
            Logger::getInstance().Write(hero2->GetName() + " won\n\n");
            break;
        }
    }
}

void Game::DumpArmy(UnitFactory::Ptr factory, Hero::Ptr hero)
{
    Logger::getInstance().Write("\tHero: " + hero->GetName() + "\n");
    Logger::getInstance().Write("\t" + factory->GetName() + " units:\n");
    UnitInfo::CollectionPtr collection;
    collection = hero->GetUnits();
    for (auto unit : *collection)
    {
        if (!unit->GetUnit()->IsComposite())
        {
            std::ostringstream oss;
            oss << "\t\t" << unit->GetUnit()->GetName() << " (" << unit->GetPosition().GetX() << ", " << unit->GetPosition().GetY() << ")" << std::endl;
            Logger::getInstance().Write(oss.str());
        }
        else
        {
            std::ostringstream oss;
            oss << "\t\tSquad " << unit->GetUnit()->GetName() << " (" << unit->GetPosition().GetX() << ", " << unit->GetPosition().GetY() << "):" << std::endl;
            Logger::getInstance().Write(oss.str());
            Unit::CollectionPtr unitsInCollection = unit->GetUnit()->GetCompositeUnit()->GetUnits();
            for (auto _unit : *unitsInCollection)
            {
                Logger::getInstance().Write("\t\t\t- " + _unit->GetName() + "\n");
            }
        }
    }
}

void Game::ClientCode()
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

    std::shared_ptr<Strategy> strategy(new SimpleStrategy);
    Hero::Ptr hero = factory->CreateHero(strategy);

    int unitId = 0;
    int x, y;
    int Power = 0;

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
            while (true)
            {
                std::cout << std::endl;
                std::cout << "Select " << factory->GetName() << " unit for the squad:" << std::endl;
                std::cout << "0 - Select complete" << std::endl;
                for (size_t i = 0; i < availableUnits.size(); ++i) {
                    std::cout << availableUnits[i].first << " - " << availableUnits[i].second << std::endl;
                }

                std::cin >> unitId;
                if (unitId == 0)
                {
                    try
                    {
                        std::cout << "Set positon: ";
                        do {
                            std::cin >> x >> y;
                            if (!BattleField::getInstance().IsFreePosition(Position(x, y)))
                                std::cout << "Position is taken.\nSetposition:";
                        } while (!BattleField::getInstance().IsFreePosition(Position(x, y)));
                        hero->AddUnit(squad, Position(x, y));
                    }
                    catch (const InvalidUnitIdException &)
                    {
                        std::cout << "Invalid Select" << std::endl;
                    }
                    break;
                }

                try {
                    Unit::Ptr unit = factory->CreateUnit(unitId);
                    Power += unit->GetPower();
                    squad->AddUnit(unit);
                }
                catch (const InvalidUnitIdException &)
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
        do {
            std::cin >> x >> y;
            if (!BattleField::getInstance().IsFreePosition(Position(x, y)))
                std::cout << "Position is taken.\nSet position: ";
        } while (!BattleField::getInstance().IsFreePosition(Position(x, y)));

        try {
            Unit::Ptr unit = factory->CreateUnit(unitId);
            Power += unit->GetPower();
            hero->AddUnit(unit, Position(x, y));
        }
        catch (const InvalidUnitIdException &)
        {
            std::cout << "Invalid Select" << std::endl;
        }
    }

    Logger::getInstance().Write("\nYour army:\n");
    Game::DumpArmy(factory, hero);

    UnitFactory::Ptr factoryRival = std::make_shared<DungeonFactory>();

    Hero::Ptr hero2;

    if (factoryId == HeavenFactoryId)
        factoryRival = std::make_shared<DungeonFactory>();
    else
        factoryRival = std::make_shared<HeavenFactory>();

    hero2 = HeroGenerator::GenerateArmyWithPower(factory, Power);

    Logger::getInstance().Write("\nRival army:\n");
    Game::DumpArmy(factoryRival, hero2);

    Logger::getInstance().Write("\n");


    Game::RunBattle(hero, hero2);

}
