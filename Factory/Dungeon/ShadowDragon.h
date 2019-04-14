#pragma once

#include "UnitBase.h"

class ShadowDragon : public UnitBase
{
public:
    ShadowDragon();
    virtual std::string GetName() const override;

    static std::string name() { return "Shadow Dragon"; }
    static int MaxPower() { return 25; }
    static int MaxProtection() { return 24; }
    static int MaxUnitsOfLife() { return 200; }
    static int MaxInitiative() { return 10; }
    static int MaxSpeed() { return 9; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};