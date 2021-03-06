#pragma once

#include "UnitBase.h"

class Angel : public UnitBase
{
public:
    Angel();
    virtual std::string GetName() const override;

    static std::string name() { return "Angel"; }
    static int MaxPower() { return 27; }
    static int MaxProtection() { return 27; }
    static int MaxUnitsOfLife() { return 180; }
    static int MaxInitiative() { return 11; }
    static int MaxSpeed() { return 6; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};