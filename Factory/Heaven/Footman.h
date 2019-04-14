#pragma once

#include "UnitBase.h"

class Footman : public UnitBase
{
public:
    Footman();
    virtual std::string GetName() const override;

    static std::string name() { return "Footman"; }
    static int MaxPower() { return 4; }
    static int MaxProtection() { return 8; }
    static int MaxUnitsOfLife() { return 16; }
    static int MaxInitiative() { return 8; }
    static int MaxSpeed() { return 4; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};