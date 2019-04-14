#pragma once

#include "UnitBase.h"

class DarkRaiden : public UnitBase
{
public:
    DarkRaiden();
    virtual std::string GetName() const override;

    static std::string name() { return "Dark Raiden"; }
    static int MaxPower() { return 9; }
    static int MaxProtection() { return 7; }
    static int MaxUnitsOfLife() { return 40; }
    static int MaxInitiative() { return 11; }
    static int MaxSpeed() { return 6; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};