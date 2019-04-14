#pragma once

#include "UnitBase.h"

class Priest : public UnitBase
{
public:
    Priest();
    virtual std::string GetName() const override;

    static std::string name() { return "Priest"; }
    static int MaxPower() { return 12; }
    static int MaxProtection() { return 12; }
    static int MaxUnitsOfLife() { return 54; }
    static int MaxInitiative() { return 10; }
    static int MaxSpeed() { return 5; }
    static int MaxStockShots() { return 7; }
    static int MaxMagicPoints() { return 0; }
};