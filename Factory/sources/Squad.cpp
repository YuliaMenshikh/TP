#include "Squad.h"
#include "Exceptions.h"
#include "Logger.h"
#include <algorithm>

Squad::Squad(const std::string &name) : _name(name), _units(new Unit::Collection)
{
}

bool Squad::IsComposite() const
{
    return true;
}

CompositeUnit* Squad::GetCompositeUnit()
{
    return this;
}

StandaloneUnit* Squad::GetStandAloneUnit()
{
    throw NotImplementedException();
}

std::string Squad::GetName() const
{
    return _name;
}

void Squad::AddUnit(Unit::Ptr unit)
{
    _units->push_back(unit);
}

int Squad::GetPower() const
{
    int power = 0;
    for (auto unit : *_units)
    {
        power += unit->GetPower();
    }
    return power;
}

int Squad::GetProtection() const
{
    int protection = 0;
    for (auto unit : *_units)
    {
        protection += unit->GetPower();
    }
    return protection;
}

int Squad::GetUnitsOfLife() const
{
    int unitsOfLife = 0;
    for (auto unit : *_units)
    {
        unitsOfLife += unit->GetPower();
    }
    return unitsOfLife;
}

int Squad::GetInitiative() const
{
    int initiative = 0;
    for (auto unit : *_units)
    {
        initiative += unit->GetPower();
    }
    return initiative;
}

int Squad::GetSpeed() const
{
    int speed = 0;
    for (auto unit : *_units)
    {
        speed += unit->GetPower();
    }
    return speed;
}

int Squad::GetStockShots() const
{
    int stockShots = 0;
    for (auto unit : *_units)
    {
        stockShots += unit->GetPower();
    }
    return stockShots;
}

int Squad::GetMagicPoints() const
{
    int magicPoints = 0;
    for (auto unit : *_units)
    {
        magicPoints += unit->GetPower();
    }
    return magicPoints;
}

Unit::CollectionPtr Squad::GetUnits() const
{
    return _units;
}

bool Squad::IsAlive() const
{
    return !_units->empty();
}

void Squad::RemoveDied()
{
    auto it = std::remove_if(_units->begin(), _units->end(), [&](const Unit::Ptr &_unit)
    {
        if (!_unit->IsAlive())
        {
            Logger::getInstance().Write(_unit->GetName() + " from the squad  " + GetName() + " was killed\n");
            return true;
        }
        return false;
    });
    if (it != _units->end())
    {
        _units->erase(it, _units->end());
    }
}