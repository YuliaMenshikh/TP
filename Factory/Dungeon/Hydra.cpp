#include "Hydra.h"

Hydra::Hydra() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string Hydra::GetName() const
{
    return name();
}