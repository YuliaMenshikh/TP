#include "Peasant.h"

Peasant::Peasant() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string Peasant::GetName() const
{
    return name();
}