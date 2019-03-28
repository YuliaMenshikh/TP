#include "BloodMaiden.h"

BloodMaiden::BloodMaiden() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string BloodMaiden::GetName() const
{
    return name();
}