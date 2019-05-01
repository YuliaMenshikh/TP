#pragma once

#include "HeroBase.h"
#include "Unit.h"

class Duncan : public HeroBase
{
public:
    virtual std::string GetName() const override
    {
        return "Duncan";
    }
};
