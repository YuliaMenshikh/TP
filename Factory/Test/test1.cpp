#include "gtest/gtest.h"
#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "SimpleStrategy.h"
#include "Squad.h"

TEST(TestGetAvailableUnits, testDungeon)
{
    UnitFactory::Ptr factory(new DungeonFactory);
    UnitFactory::UnitItems availableUnits;
    factory->GetAvailableUnits(availableUnits);

    for (size_t i = 0; i < availableUnits.size(); ++i)
    {
        const int &unitId = availableUnits[i].first;
        const std::string &unitName = availableUnits[i].second;
        Unit::Ptr unit = factory->CreateUnit(unitId);
        EXPECT_TRUE(unit);
        EXPECT_EQ(unitName, unit->GetName());
    }
}

TEST(TestGetAvailableUnits, testHeaven)
{
    UnitFactory::Ptr factory(new HeavenFactory);
    UnitFactory::UnitItems availableUnits;
    factory->GetAvailableUnits(availableUnits);

    for (size_t i = 0; i < availableUnits.size(); ++i)
    {
        const int &unitId = availableUnits[i].first;
        const std::string &unitName = availableUnits[i].second;
        Unit::Ptr unit = factory->CreateUnit(unitId);
        EXPECT_TRUE(unit);
        EXPECT_EQ(unitName, unit->GetName());
    }

}

TEST(TestGetHero, testDungeon)
{
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);
    UnitFactory::Ptr factory(new DungeonFactory);
    Hero::Ptr hero = factory->CreateHero(strategy);
    EXPECT_EQ(hero->GetName(), "Ylaya");
}

TEST(TestGetHero, testHeaven)
{
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);
    UnitFactory::Ptr factory(new HeavenFactory);
    Hero::Ptr hero = factory->CreateHero(strategy);
    EXPECT_EQ(hero->GetName(), "Duncan");
}

TEST(TestCreateUnit, testDungeonScout)
{
    UnitFactory::Ptr factory(new DungeonFactory);
    Unit::Ptr DungeonScout = factory->CreateUnit(1);
    EXPECT_TRUE(DungeonScout);
    EXPECT_EQ(DungeonScout->GetName(), "Scout");
    EXPECT_EQ(DungeonScout->GetPower(), 3);
    EXPECT_EQ(DungeonScout->GetProtection(), 3);
    EXPECT_EQ(DungeonScout->GetUnitsOfLife(), 10);
    EXPECT_EQ(DungeonScout->GetInitiative(), 10);
    EXPECT_EQ(DungeonScout->GetSpeed(), 5);
    EXPECT_EQ(DungeonScout->GetStockShots(), 5);
    EXPECT_EQ(DungeonScout->GetMagicPoints(), 0);
}

TEST(TestGetName, testDungeon)
{
    UnitFactory::Ptr factory(new DungeonFactory);
    EXPECT_EQ(factory->GetName(), "Dungeon");
}

TEST(TestGetName, testHeaven)
{
    UnitFactory::Ptr factory(new HeavenFactory);
    EXPECT_EQ(factory->GetName(), "Heaven");
}

/*TEST(TestStrategy, MakeStep)
{
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);

    UnitFactory::Ptr factory1 = std::make_shared<DungeonFactory>();
    std::shared_ptr<Squad> squad(new Squad("1 squad"));
    squad->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonScout));
    squad->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonDarkRaiden));

    Hero::Ptr hero1 = factory1->CreateHero(strategy);
    hero1->AddUnit(squad, Position(1, 1));
    hero1->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonMinotaur), Position(3, 7));

    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();
    Hero::Ptr hero2 = factory2->CreateHero(strategy);
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPeasant), Position(5, 6));
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenFootman), Position(2, 2));
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPriest), Position(5, 1));
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenCavalier), Position(1, 2));

    for (int i = 0; i < 20; ++i)
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
}*/

TEST(TestStrategy, MoveTo)
{
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);

    UnitFactory::Ptr factory1 = std::make_shared<DungeonFactory>();
    Hero::Ptr hero1 = factory1->CreateHero(strategy);
    hero1->AddUnit(factory1->CreateUnit(DungeonFactory::DungeonMinotaur), Position(3, 7));

    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();
    Hero::Ptr hero2 = factory2->CreateHero(strategy);
    hero2->AddUnit(factory2->CreateUnit(HeavenFactory::HeavenPeasant), Position(5, 6));

    UnitInfo::CollectionPtr units1 = hero1->GetUnits();
    UnitInfo::CollectionPtr units2 = hero2->GetUnits();
    UnitInfo::Ptr unit1, unit2;
    for (auto unitFrom : *units1)
    {
        unit1 = unitFrom;
    }
    for (auto unitTo : *units2)
    {
        unit2 = unitTo;
    }
    int distanceBefore = GetDistance(unit1->GetPosition(), unit2->GetPosition());
    hero1->MakeStep(*hero2);

    int distanceAfter = GetDistance(unit1->GetPosition(), unit2->GetPosition());

    EXPECT_TRUE(distanceBefore == distanceAfter + 1);
}

TEST(TestBattleField, BattleField1)
{
    std::shared_ptr<Strategy> strategy(new SimpleStrategy);

    UnitFactory::Ptr factory = std::make_shared<DungeonFactory>();
    Position position1(6, 6);
    Position position2(6, 7);
    factory->CreateHero(strategy)->AddUnit(factory->CreateUnit(DungeonFactory::DungeonHydra), position1);
    factory->CreateHero(strategy)->AddUnit(factory->CreateUnit(DungeonFactory::DungeonBloodMaiden), position2);
}

