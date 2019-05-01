#include "HeroBase.h"

#include <algorithm>

UnitInfo::CollectionPtr HeroBase::GetUnits() const
{
    return  _units;
}

void HeroBase::AddUnit(Unit::Ptr unit, const Position &position)
{
    _units->push_back(std::shared_ptr<UnitInfo>(new UnitInfo(unit, position)));
}

void HeroBase::RemoveDied()
{
    auto it = std::remove_if(_units->begin(), _units->end(), [&](const UnitInfo::Ptr &_unitInfo)
    {
        if (!_unitInfo->GetUnit()->IsAlive())
        {
            std::cout << _unitInfo->GetUnit()->GetName() << " убит" << std::endl;
            return true;
        }
        return false;
    });
    if (it != _units->end())
    {
        _units->erase(it, _units->end());
    }
}

bool HeroBase::HasUnits() const
{
    return !_units->empty();
}

