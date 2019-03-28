#include "ShadowWitch.h"

ShadowWitch::ShadowWitch() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string ShadowWitch::GetName() const
{
    return name();
}