#pragma once

#include "Hero.h"
#include "UnitFactory.h"

namespace HeroGenerator
{
    void RandomString(std::string& name, size_t length);
    Hero::Ptr GenerateArmyWithPower(UnitFactory::Ptr factory, int power);
}