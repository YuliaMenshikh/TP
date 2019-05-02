#pragma once

#include "Hero.h"
#include <memory>

struct Strategy
{
    typedef std::shared_ptr<Strategy> Ptr;

    virtual ~Strategy() {}
    virtual void MakeStep(Hero &heroFrom, Hero &heroTo) = 0;
};
