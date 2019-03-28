#include "Archer.h"

Archer::Archer() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string Archer::GetName() const
{
    return name();
}