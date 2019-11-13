#pragma once

#include <string>
#include <vector>
#include <utility>
#include "Hero.h"
#include "Unit.h"
#include "Strategy.h"

#include <memory>

struct UnitFactory
{
    typedef std::shared_ptr<UnitFactory> Ptr;
    typedef std::pair<int, std::string> UnitItem;
    typedef std::vector<UnitItem> UnitItems;

    virtual ~UnitFactory() {}
    virtual void GetAvailableUnits(UnitItems& units) const = 0;
    virtual Hero::Ptr CreateHero(Strategy::Ptr strategy) const = 0;
    virtual Unit::Ptr CreateUnit(int unitId) const = 0;
    virtual std::string GetName() const = 0;
};
