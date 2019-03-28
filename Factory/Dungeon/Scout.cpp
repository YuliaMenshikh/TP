#include "Scout.h"

Scout::Scout() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string Scout::GetName() const
{
    return name();
}