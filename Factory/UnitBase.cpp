#include "UnitBase.h"
#include "Exceptions.h"

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

bool UnitBase::IsComposite() const
{
    return false;
}

CompositeUnit* UnitBase::GetCompositeUnit()
{
    throw NotImplementedException();
}

StandaloneUnit* UnitBase::GetStandAloneUnit()
{
    return this;
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

/*Unit::CollectionPtr UnitBase::GetUnits() const
{
    throw GameException("UnitBase::GetUnits() called");
}*/

void UnitBase::DecreaseUnitsOfLife(int amount)
{
    _unitsOfLife -= amount;
    if (_unitsOfLife < 0)
        _unitsOfLife = 0;
}

bool UnitBase::IsAlive() const
{
    return _unitsOfLife > 0;
}

/*void UnitBase::RemoveDied()
{
    throw GameException("UnitBase::RemoveDied() called");
}*/