#pragma once

#include "Hero.h"

namespace Game
{
    void RunGame();
    Hero::Ptr ConstructYalayaArmy();
    Hero::Ptr ConstructDuncanArmy();
    void RunBattle(Hero::Ptr hero1, Hero::Ptr hero2);
}