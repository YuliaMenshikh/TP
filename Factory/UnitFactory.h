#pragma once

#include <string>
#include <vector>
#include <utility>
#include "Unit.h"

struct UnitFactory
{
    typedef std::pair<int, std::string> UnitItem;
    typedef std::vector<UnitItem> UnitItems;

    virtual void GetAvailableUnits(UnitItems& units) const = 0;
    virtual Unit* CreateUnit(int unitId) const = 0;
    virtual std::string GetName() const = 0;
};
