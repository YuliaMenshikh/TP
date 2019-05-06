#pragma once

#include "Decorator.h"
#include "Exceptions.h"

bool Decorator::IsComposite() const
{
    return  _unit->IsComposite();
}

CompositeUnit* Decorator::GetCompositeUnit()
{
    return _unit->GetCompositeUnit();
}

StandaloneUnit* Decorator::GetStandAloneUnit()
{
    return _unit->GetStandAloneUnit();
}

std::string Decorator::GetName() const
{
    return _unit->GetName();
}

int Decorator::GetPower() const
{
    return _unit->GetPower();
}

int Decorator::GetProtection() const
{
    return _unit->GetProtection();
}

int Decorator::GetUnitsOfLife() const
{
    return _unit->GetUnitsOfLife();
}

int Decorator::GetInitiative() const
{
    return _unit->GetInitiative();
}

int Decorator::GetSpeed() const
{
    return _unit->GetSpeed();
}

int Decorator::GetStockShots() const
{
    return _unit->GetStockShots();
}
int Decorator::GetMagicPoints() const
{
    return _unit->GetMagicPoints();
}

bool Decorator::IsAlive() const
{
    return _unit->IsAlive();
}