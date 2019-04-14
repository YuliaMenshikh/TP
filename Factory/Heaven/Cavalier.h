#pragma once

#include "UnitBase.h"

class Cavalier : public UnitBase
{
public:
    Cavalier();
    virtual std::string GetName() const override;

    static std::string name() { return "Cavalier"; }
    static int MaxPower() { return 23; }
    static int MaxProtection() { return 21; }
    static int MaxUnitsOfLife() { return 90; }
    static int MaxInitiative() { return 11; }
    static int MaxSpeed() { return 7; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};