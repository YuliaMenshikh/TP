#include "DarkRaiden.h"

DarkRaiden::DarkRaiden() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string DarkRaiden::GetName() const
{
    return name();
}