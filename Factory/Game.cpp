#include "Game.h"
#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "SimpleStrategy.h"
#include "Strategy1.h"
#include "Squad.h"
#include "DoubleHealthUnitDecorator.h"
#include "Logger.h"

void  Game::RunGame()
{
    Hero::Ptr hero1 = ConstructYalayaArmy();
    Hero::Ptr hero2 = ConstructDuncanArmy();
    RunBattle(hero1, hero2);
}

Hero::Ptr Game::ConstructYalayaArmy()
{
    std::shared_ptr<Strategy> strategy(new Strategy1);

    UnitFactory::Ptr factory1 = std::make_shared<DungeonFactory>();
    std::shared_ptr<Squad> squad(new Squad("Yalaya squad1"));
    squad->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonScout));
    squad->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonDarkRaiden));

    Hero::Ptr hero1 = factory1->CreateHero(strategy);
    hero1->AddUnit(squad, Position(1, 1));
    Unit::Ptr decoratedUnit(new DoubleHealthUnitDecorator(factory1->CreateUnit(DungeonFactory::DungeonDarkRaiden)));
    hero1->AddUnit(decoratedUnit, Position(1, 3));
    return hero1;
}

Hero::Ptr Game::ConstructDuncanArmy()
{
    std::shared_ptr<Strategy> strategy(new Strategy1);

    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();
    Hero::Ptr hero2 = factory2->CreateHero(strategy);
    std::shared_ptr<Squad> squad(new Squad("Duncan squad2"));
    squad->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPeasant));
    squad->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenFootman));

    hero2->AddUnit(squad, Position(1, 2));
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPriest), Position(2, 1));
    return hero2;
}

void Game::RunBattle(Hero::Ptr hero1, Hero::Ptr hero2)
{
    while (true)
    {
        hero1->MakeStep(*hero2);
        if (!hero2->HasUnits())
        {
            Logger::getInstance().Write("Армия героя " + hero2->GetName() + " уничтожена" + "\n");
            Logger::getInstance().Write("Вы победили\n");
            break;
        }

        hero2->MakeStep(*hero1);
        if (!hero1->HasUnits())
        {
            Logger::getInstance().Write("Армия героя " + hero1->GetName() + " уничтожена" + "\n");
            Logger::getInstance().Write("Вы проиграли\n");
            break;
        }
    }
}
