#include "HeroBase.h"
#include "Logger.h"

#include <algorithm>

HeroBase::HeroBase(Strategy::Ptr strategy) : _strategy(strategy), _units(std::make_shared<UnitInfo::Collection>()) {}

void HeroBase::MakeStep(Hero &heroTo)
{
    _strategy->MakeStep(*this, heroTo);
}

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
        Unit::Ptr _unit = _unitInfo->GetUnit();
        if (_unit->IsComposite())
        {
            _unit->GetCompositeUnit()->RemoveDied();
        }

        if (!_unit->IsAlive())
        {
            Logger::getInstance().Write(_unit->GetName() + " убит\n");
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

