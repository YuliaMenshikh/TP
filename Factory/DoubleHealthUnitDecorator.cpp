#include "DoubleHealthUnitDecorator.h"
#include "Exceptions.h"

void DoubleHealthUnitDecorator::DecreaseUnitsOfLife(int amount)
{
    GetStandAloneUnit()->DecreaseUnitsOfLife(amount / 2);
}