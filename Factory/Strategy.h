#pragma once

#include "Hero.h"

struct Strategy
{
    virtual void MakeStep(Hero::Ptr heroFrom, Hero::Ptr heroTo) = 0;
};
