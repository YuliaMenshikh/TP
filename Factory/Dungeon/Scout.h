#pragma once

#include "UnitBase.h"

class Scout : public UnitBase
{
public:
    Scout();
    virtual std::string GetName() const override;

    static std::string name() { return "Scout"; }
    static int MaxPower() { return 3; }
    static int MaxProtection() { return 3; }
    static int MaxUnitsOfLife() { return 10; }
    static int MaxInitiative() { return 10; }
    static int MaxSpeed() { return 5; }
    static int MaxStockShots() { return 5; }
    static int MaxMagicPoints() { return 0; }
};