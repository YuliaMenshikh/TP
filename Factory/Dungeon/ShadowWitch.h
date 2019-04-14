#pragma once

#include "UnitBase.h"

class ShadowWitch : public UnitBase
{
public:
    ShadowWitch();
    virtual std::string GetName() const override;

    static std::string name() { return "Shadow Witch"; }
    static int MaxPower() { return 18; }
    static int MaxProtection() { return 18; }
    static int MaxUnitsOfLife() { return 80; }
    static int MaxInitiative() { return 10; }
    static int MaxSpeed() { return 4; }
    static int MaxStockShots() { return 4; }
    static int MaxMagicPoints() { return 11; }
};