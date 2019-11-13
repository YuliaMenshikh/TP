#pragma once

#include "Hero.h"
#include "UnitFactory.h"

namespace Game
{
    void RunGame();
    void ClientCode();
    void RunBattle(Hero::Ptr hero1, Hero::Ptr hero2);
    void DumpArmy(UnitFactory::Ptr factory, Hero::Ptr);
}