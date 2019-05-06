#pragma once

#include "UnitDecorator.h"

class DoubleHealthUnitDecorator : public UnitDecorator, public StandaloneUnit
{
public:
    DoubleHealthUnitDecorator(Unit::Ptr unit);

    virtual void DecreaseUnitsOfLife(int amount) override;
};