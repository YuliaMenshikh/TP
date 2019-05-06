#pragma once

#include "Decorator.h"

class DoubleHealthUnitDecorator : public Decorator
{
public:
    DoubleHealthUnitDecorator(Unit::Ptr unit) : Decorator(unit) {}

    virtual void DecreaseUnitsOfLife(int amount) override;
};