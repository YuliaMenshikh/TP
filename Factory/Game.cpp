#include "Game.h"
#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "SimpleStrategy.h"
#include "Strategy1.h"
#include "Squad.h"

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
    hero1->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonMinotaur), Position(1, 4));
    return hero1;
}

Hero::Ptr Game::ConstructDuncanArmy()
{
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);

    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();
    Hero::Ptr hero2 = factory2->CreateHero(strategy);
    std::shared_ptr<Squad> squad(new Squad("Duncan squad2"));
    squad->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPeasant));
    squad->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenFootman));

    hero2->AddUnit(squad, Position(5, 6));
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPriest), Position(1, 2));
    return hero2;
}

void Game::RunBattle(Hero::Ptr hero1, Hero::Ptr hero2)
{
    while (true)
    {
        hero1->MakeStep(*hero2);
        if (!hero2->HasUnits())
        {
            std::cout << "Армия героя " << hero2->GetName() << " уничтожена" << std::endl;
            break;
        }

        hero2->MakeStep(*hero1);
        if (!hero1->HasUnits())
        {
            std::cout << "Армия героя " << hero1->GetName() << " уничтожена" << std::endl;
            break;
        }
    }
}
