#pragma once

#include "UnitBase.h"

class Hydra : public UnitBase
{
public:
    Hydra();
    virtual std::string GetName() const override;

    static std::string name() { return "Hydra"; }
    static int MaxPower() { return 15; }
    static int MaxProtection() { return 12; }
    static int MaxUnitsOfLife() { return 80; }
    static int MaxInitiative() { return 7; }
    static int MaxSpeed() { return 5; }
    static int MaxStockShots() { return 0; }
    static int MaxMagicPoints() { return 0; }
};