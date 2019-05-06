#pragma once

#include "Unit.h"

class Decorator : public Unit, public StandaloneUnit
{
public:
    Decorator(Unit::Ptr unit) : _unit(unit) {}

    virtual bool IsComposite() const override;
    virtual CompositeUnit* GetCompositeUnit() override;
    virtual StandaloneUnit* GetStandAloneUnit() override;

    virtual std::string GetName() const override;
    virtual int GetPower() const override;
    virtual int GetProtection() const override;
    virtual int GetUnitsOfLife() const override;
    virtual int GetInitiative() const override;
    virtual int GetSpeed() const override;
    virtual int GetStockShots() const override;
    virtual int GetMagicPoints() const override;

    virtual bool IsAlive() const override;

protected:
    Unit::Ptr _unit;
};