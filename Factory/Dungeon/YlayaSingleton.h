#pragma once

#include "HeroBase.h"
#include "Unit.h"

class Ylaya : public HeroBase
{
public:
    virtual std::string GetName() const override
    {
        return "Ylaya";
    }
};
