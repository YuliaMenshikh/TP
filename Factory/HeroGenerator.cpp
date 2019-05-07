#include "HeroGenerator.h"
#include "Hero.h"
#include "Strategy1.h"
#include "SimpleStrategy.h"
#include "Squad.h"
#include "Heaven/HeavenFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "DoubleHealthUnitDecorator.h"
#include "BattleField.h"
#include <random>

std::string HeroGenerator::RandomString(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

Hero::Ptr HeroGenerator::GenerateArmyWithPower(UnitFactory::Ptr factory, int power)
{

    std::random_device rd;
    std::default_random_engine generator(rd());

    std::shared_ptr<Strategy> strategy(new SimpleStrategy);
    Hero::Ptr hero = factory->CreateHero(strategy);

    Unit::CollectionPtr unitCollection(new Unit::Collection);
    int CurrentPower = 0;

    while(CurrentPower < power)
    {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_int_distribution<int> distributionOfUnitId(1, 7);
        int unitId = distributionOfUnitId(generator);
        unitCollection->push_back(factory->CreateUnit(unitId));
        CurrentPower += unitCollection->back()->GetPower();
    }

    while(!unitCollection->empty())
    {
        bool ifSquad = false;
        std::uniform_int_distribution<int> distributionCreateSquad(1, 10);
        int SquadGenerator = distributionCreateSquad(generator);
        if (SquadGenerator > 6)
        {
            std::string SquadName = RandomString(7);
            std::shared_ptr<Squad> squad(new Squad(SquadName));
            std::uniform_int_distribution<int> distributionNumberOfUnits(1, unitCollection->size());
            int NumberOfUnits = distributionNumberOfUnits(generator);
            while (NumberOfUnits)
            {
                squad->AddUnit(unitCollection->back());
                unitCollection->pop_back();
                NumberOfUnits--;
            }
            std::uniform_int_distribution<int> distributionOfPosition(1, 50);
            int x, y;
            do
            {
                x = distributionOfPosition(generator);
                y = distributionOfPosition(generator);
            } while (!BattleField::getInstance().IsFreePosition(Position(x, y)));
            hero->AddUnit(squad, Position(x, y));
        }
        else
        {
            std::uniform_int_distribution<int> distributionOfPosition(1, 50);
            int x, y;
            do
            {
                x = distributionOfPosition(generator);
                y = distributionOfPosition(generator);
            } while (!BattleField::getInstance().IsFreePosition(Position(x, y)));
            hero->AddUnit(unitCollection->back(), Position(x, y));
            unitCollection->pop_back();
        }
    }
    return hero;
}