#include "Griffin.h"

Griffin::Griffin() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string Griffin::GetName() const
{
    return name();
}