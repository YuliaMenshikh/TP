#pragma once

#include "UnitBase.h"

class Archer : public UnitBase
{
public:
    Archer();
    virtual std::string GetName() const override;

    static std::string name() { return "Archer"; }
    static int MaxPower() { return 4; }
    static int MaxProtection() { return 3; }
    static int MaxUnitsOfLife() { return 7; }
    static int MaxInitiative() { return 9; }
    static int MaxSpeed() { return 4; }
    static int MaxStockShots() { return 10; }
    static int MaxMagicPoints() { return 0; }
};