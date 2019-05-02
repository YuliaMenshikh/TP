#pragma once

#include "HeroBase.h"
#include "Unit.h"

class Ylaya : public HeroBase
{
public:
    Ylaya(Strategy::Ptr strategy) : HeroBase(strategy) {}

    virtual std::string GetName() const override
    {
        return "Ylaya";
    }
};
