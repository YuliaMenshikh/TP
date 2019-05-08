#include "gtest/gtest.h"
#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"
#include "SimpleStrategy.h"
#include "Squad.h"
#include "HeroGenerator.h"

#include <ctime>

TEST(StressTest, stress1)
{
    const clock_t beginTime = clock();

    UnitFactory::Ptr factory1 = std::make_shared<DungeonFactory>();
    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();
    HeroGenerator::GenerateArmyWithPower(factory1, 1000000);
    HeroGenerator::GenerateArmyWithPower(factory2, 1000000);

    const clock_t endTime = clock();
    EXPECT_TRUE(endTime - beginTime < 10000000);
}

TEST(LoadTest, load)
{
    const clock_t beginTime = clock();

    UnitFactory::Ptr factory1 = std::make_shared<DungeonFactory>();
    UnitFactory::Ptr factory2 = std::make_shared<HeavenFactory>();
    HeroGenerator::GenerateArmyWithPower(factory1, 1000);
    HeroGenerator::GenerateArmyWithPower(factory2, 1000);

    const clock_t endTime = clock();
    EXPECT_TRUE(endTime - beginTime < 10000);
}

