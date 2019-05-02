#pragma once

#include "Unit.h"
#include "Position.h"

class UnitBase: public Unit, public StandaloneUnit
{
public:
    UnitBase(int MaxPower, int MaxProtection, int MaxUnitsOfLife,
            int MaxInitiative, int MaxSpeed, int MaxStockShots, int MaxMagicPoints);

    virtual bool IsComposite() const override;
    virtual CompositeUnit* GetCompositeUnit() override;
    virtual StandaloneUnit* GetStandAloneUnit() override;

    virtual int GetPower() const override;
    virtual int GetProtection() const override;
    virtual int GetUnitsOfLife() const override;
    virtual int GetInitiative() const override;
    virtual int GetSpeed() const override;
    virtual int GetStockShots() const override;
    virtual int GetMagicPoints() const override;

    //virtual Unit::CollectionPtr GetUnits() const override;

    virtual void DecreaseUnitsOfLife(int amount) override;

    virtual bool IsAlive() const override;

    //virtual void RemoveDied() override;

private:
    int _power;
    int _protection;
    int _unitsOfLife;
    int _initiative;
    int _speed;
    int _stockShots;
    int _magicPoints;
};

