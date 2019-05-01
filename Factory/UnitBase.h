#pragma once

#include "Unit.h"
#include "Position.h"

class UnitBase: public Unit
{
public:
    UnitBase(int MaxPower, int MaxProtection, int MaxUnitsOfLife,
            int MaxInitiative, int MaxSpeed, int MaxStockShots, int MaxMagicPoints);
    virtual int GetPower() const override;
    virtual int GetProtection() const override;
    virtual int GetUnitsOfLife() const override;
    virtual int GetInitiative() const override;
    virtual int GetSpeed() const override;
    virtual int GetStockShots() const override;
    virtual int GetMagicPoints() const override;

    virtual void DecreaseUnitsOfLfe(int amount) override;

    virtual bool IsAlive() const override;

private:
    int _power;
    int _protection;
    int _unitsOfLife;
    int _initiative;
    int _speed;
    int _stockShots;
    int _magicPoints;
};

