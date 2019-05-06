#include "DoubleHealthUnitDecorator.h"
#include "Exceptions.h"

DoubleHealthUnitDecorator::DoubleHealthUnitDecorator(Unit::Ptr unit) : UnitDecorator(unit) {}

void DoubleHealthUnitDecorator::DecreaseUnitsOfLife(int amount)
{
    GetStandAloneUnit()->DecreaseUnitsOfLife(amount / 2);
}