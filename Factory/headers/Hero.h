#pragma once

#include "UnitInfo.h"
#include <string>
#include <vector>

struct Hero
{
    typedef std::shared_ptr<Hero> Ptr;

    virtual void MakeStep(Hero &heroTo) = 0;
    virtual std::string GetName() const = 0;
    virtual void AddUnit(Unit::Ptr unit, const Position &position) = 0;
    virtual UnitInfo::CollectionPtr GetUnits() const = 0;
    virtual void RemoveDied() = 0;
    virtual bool HasUnits() const = 0;
};
