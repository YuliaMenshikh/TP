#pragma once

#include "Hero.h"
#include "UnitFactory.h"

namespace HeroGenerator
{
    std::string RandomString(size_t length);
    Hero::Ptr GenerateArmyWithPower(UnitFactory::Ptr factory, int power);
}