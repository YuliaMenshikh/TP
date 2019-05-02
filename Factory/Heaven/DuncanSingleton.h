#pragma once

#include "HeroBase.h"
#include "Unit.h"

class Duncan : public HeroBase
{
public:
    Duncan(Strategy::Ptr strategy) : HeroBase(strategy) {}

    virtual std::string GetName() const override
    {
        return "Duncan";
    }
};
