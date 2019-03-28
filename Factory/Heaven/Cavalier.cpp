#include "Cavalier.h"

Cavalier::Cavalier() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string Cavalier::GetName() const
{
    return name();
}