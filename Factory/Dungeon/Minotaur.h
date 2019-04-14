#pragma once

#include "UnitBase.h"

class Minotaur : public UnitBase
{
public:
    Minotaur();
    virtual std::string GetName() const override;

    static std::string name() { return "Minotaur"; }
    static int MaxPower() { return 5; }
    static int MaxProtection() { return 2; }
    static int MaxUnitsOfLife() { return 31; }
    static int MaxInitiative() { return 8; }
    static int MaxSpeed() { return 5; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};