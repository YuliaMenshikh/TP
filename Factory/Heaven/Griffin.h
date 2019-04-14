#pragma once

#include "UnitBase.h"

class Griffin : public UnitBase
{
public:
    Griffin();
    virtual std::string GetName() const override;

    static std::string name() { return "Griffin"; }
    static int MaxPower() { return 7; }
    static int MaxProtection() { return 5; }
    static int MaxUnitsOfLife() { return 30; }
    static int MaxInitiative() { return 15; }
    static int MaxSpeed() { return 7; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};