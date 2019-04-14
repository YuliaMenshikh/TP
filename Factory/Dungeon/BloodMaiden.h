#pragma once

#include "UnitBase.h"

class BloodMaiden : public UnitBase
{
public:
    BloodMaiden();
    virtual std::string GetName() const override;

    static std::string name() { return "Blood Maiden"; }
    static int MaxPower() { return 4; }
    static int MaxProtection() { return 2; }
    static int MaxUnitsOfLife() { return 16; }
    static int MaxInitiative() { return 14; }
    static int MaxSpeed() { return 7; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};