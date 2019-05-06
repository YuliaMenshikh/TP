#include "DoubleHealthUnitDecorator.h"

DoubleHealthUnitDecorator::DoubleHealthUnitDecorator(Unit::Ptr unit) : UnitDecorator(unit) {}

StandaloneUnit* DoubleHealthUnitDecorator::GetStandAloneUnit()
{
    return this;
}

void DoubleHealthUnitDecorator::DecreaseUnitsOfLife(int amount)
{
    _unit->GetStandAloneUnit()->DecreaseUnitsOfLife(amount / 2);
}