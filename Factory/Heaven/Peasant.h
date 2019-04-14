#pragma once

#include "UnitBase.h"

class Peasant : public UnitBase
{
public:
    Peasant();
    virtual std::string GetName() const override;

    static std::string name() { return "Peasant"; }
    static int MaxPower() { return 1; }
    static int MaxProtection() { return 1; }
    static int MaxUnitsOfLife() { return 3; }
    static int MaxInitiative() { return 8; }
    static int MaxSpeed() { return 4; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};