#include "UnitBase.h"

UnitBase::UnitBase(int MaxPower, int MaxProtection, int MaxUnitsOfLife, int MaxInitiative, int MaxSpeed,
                   int MaxStockShots, int MaxMagicPoints) : _power(MaxPower),
                                                            _protection(MaxProtection),
                                                            _unitsOfLife(MaxUnitsOfLife),
                                                            _initiative(MaxInitiative),
                                                            _speed(MaxSpeed),
                                                            _stockShots(MaxStockShots),
                                                            _magicPoints(MaxMagicPoints)
{
}

int UnitBase::GetPower() const
{
    return _power;
}

int UnitBase::GetProtection() const
{
    return _protection;
}

int UnitBase::GetUnitsOfLife() const
{
    return _unitsOfLife;
}

int UnitBase::GetInitiative() const
{
    return _initiative;
}

int UnitBase::GetSpeed() const
{
    return _speed;
}

int UnitBase::GetStockShots() const
{
    return _stockShots;
}

int UnitBase::GetMagicPoints() const
{
    return _magicPoints;
}
