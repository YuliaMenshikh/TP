#include "Minotaur.h"

Minotaur::Minotaur() : UnitBase(MaxPower(), MaxProtection(), MaxUnitsOfLife(), MaxInitiative(), MaxSpeed(), MaxStockShots(), MaxMagicPoints())
{
}

std::string Minotaur::GetName() const
{
    return name();
}