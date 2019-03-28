#include "ShadowDragon.h"

ShadowDragon::ShadowDragon() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string ShadowDragon::GetName() const
{
    return name();
}