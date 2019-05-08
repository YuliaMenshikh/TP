#include "UnitDecorator.h"
#include "Exceptions.h"

bool UnitDecorator::IsComposite() const
{
    return  _unit->IsComposite();
}

CompositeUnit* UnitDecorator::GetCompositeUnit()
{
    return _unit->GetCompositeUnit();
}

StandaloneUnit* UnitDecorator::GetStandAloneUnit()
{
    return _unit->GetStandAloneUnit();
}

std::string UnitDecorator::GetName() const
{
    return _unit->GetName();
}

int UnitDecorator::GetPower() const
{
    return _unit->GetPower();
}

int UnitDecorator::GetProtection() const
{
    return _unit->GetProtection();
}

int UnitDecorator::GetUnitsOfLife() const
{
    return _unit->GetUnitsOfLife();
}

int UnitDecorator::GetInitiative() const
{
    return _unit->GetInitiative();
}

int UnitDecorator::GetSpeed() const
{
    return _unit->GetSpeed();
}

int UnitDecorator::GetStockShots() const
{
    return _unit->GetStockShots();
}
int UnitDecorator::GetMagicPoints() const
{
    return _unit->GetMagicPoints();
}

bool UnitDecorator::IsAlive() const
{
    return _unit->IsAlive();
}