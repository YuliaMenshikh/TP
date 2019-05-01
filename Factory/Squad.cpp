#include "Squad.h"

Squad::Squad(const std::string &name) : _name(name)
{
}

std::string Squad::GetName() const
{
    return _name;
}

void Squad::AddUnit(Unit::Ptr unit, const Position &position)
{
    _units.push_back(std::shared_ptr<UnitInfo>(new UnitInfo(unit, position)));
}

int Squad::GetPower() const
{
    int power = 0;
    for (auto unit : _units)
    {
        power += unit->GetUnit()->GetPower();
    }
    return power;
}

int Squad::GetProtection() const
{
    int protection = 0;
    for (auto unit : _units)
    {
        protection += unit->GetUnit()->GetPower();
    }
    return protection;
}

int Squad::GetUnitsOfLife() const
{
    int unitsOfLife = 0;
    for (auto unit : _units)
    {
        unitsOfLife += unit->GetUnit()->GetPower();
    }
    return unitsOfLife;
}

int Squad::GetInitiative() const
{
    int initiative = 0;
    for (auto unit : _units)
    {
        initiative += unit->GetUnit()->GetPower();
    }
    return initiative;
}

int Squad::GetSpeed() const
{
    int speed = 0;
    for (auto unit : _units)
    {
        speed += unit->GetUnit()->GetPower();
    }
    return speed;
}

int Squad::GetStockShots() const
{
    int stockShots = 0;
    for (auto unit : _units)
    {
        stockShots += unit->GetUnit()->GetPower();
    }
    return stockShots;
}

int Squad::GetMagicPoints() const
{
    int magicPoints = 0;
    for (auto unit : _units)
    {
        magicPoints += unit->GetUnit()->GetPower();
    }
    return magicPoints;
}