#include "Strategy1.h"
#include "Exceptions.h"
#include "BattleField.h"
#include "Logger.h"

#include <algorithm>
#include <climits>
#include <sstream>

void Strategy1::MakeStep(Hero &heroFrom, Hero &heroTo)
{
    Unit::Ptr unitFrom;
    Unit::Ptr unitTo;

    if (GetStandaloneUnitToAttackAndKill(heroFrom, heroTo, unitFrom, unitTo))
    {
        Logger::getInstance().Write(unitFrom->GetName() + " attacked " + unitTo->GetName() + "\n");
        ExecuteCommand(Command::Ptr(new AttackCommand(unitFrom, heroTo, unitTo)));
        return;
    }
    if (GetStandaloneUnitToAttack(heroFrom, heroTo, unitFrom, unitTo))
    {
        Logger::getInstance().Write(unitFrom->GetName() + " attacked " + unitTo->GetName() + "\n");
        ExecuteCommand(Command::Ptr(new AttackCommand(unitFrom, heroTo, unitTo)));
        return;
    }

    UnitInfo::Ptr unitInfoFrom;

    bool moved = false;

    Direction direction;

    if (GetUnitToMove(heroFrom, heroTo, unitInfoFrom, direction))
    {
        ExecuteCommand(Command::Ptr(new MoveCommand(unitInfoFrom, direction)));
        moved = true;
    }

    if (moved)
    {
        std::ostringstream oss;
        oss << unitInfoFrom->GetUnit()->GetName() << " took a step to position (" << unitInfoFrom->GetPosition().GetX() << ", " << unitInfoFrom->GetPosition().GetY() << ")" << "\n";
        Logger::getInstance().Write(oss.str());
    }
    else
    {
        Logger::getInstance().Write(heroFrom.GetName() + "'s army no one to move");
    }
}

Unit::Ptr UnitWithMaxPower(Unit::CollectionPtr units)
{
    Unit::Ptr unit;
    int maxPower = 0;
    for (auto _unit : *units)
    {
        if (_unit->GetPower() > maxPower)
        {
            maxPower = _unit->GetPower();
            unit = _unit;
        }
    }

    if (!unit)
        throw GameException("Empty Unit::Collection");

    return unit;
}

Unit::Ptr UnitWithMinHealth(Unit::CollectionPtr units)
{
    Unit::Ptr unit;
    int minHealth = INT_MAX;
    for (auto _unit : *units)
    {
        if (_unit->GetUnitsOfLife() < minHealth)
        {
            minHealth = _unit->GetUnitsOfLife();
            unit = _unit;
        }
    }

    if (!unit)
        throw GameException("Empty Unit::Collection");

    return unit;
}

bool Strategy1::GetStandaloneUnitToAttackAndKill(Hero &heroFrom, Hero &heroTo, Unit::Ptr &unitFrom, Unit::Ptr &unitTo)
{
    UnitInfo::CollectionPtr unitsInfoFrom = heroFrom.GetUnits();
    UnitInfo::CollectionPtr unitsInfoTo = heroTo.GetUnits();

    for (auto _unitInfoFrom : *unitsInfoFrom)
    {
        auto it = std::find_if(unitsInfoTo->begin(), unitsInfoTo->end(), [&_unitInfoFrom](const UnitInfo::Ptr &_unitInfoTo)
        {
            if (!AreNeighbours(_unitInfoFrom->GetPosition(), _unitInfoTo->GetPosition()))
                return false;

            Unit::Ptr _unitFrom = _unitInfoFrom->GetUnit();
            int PowerFrom, PowerTo;
            int HealthFrom, HealthTo;
            if (_unitFrom->IsComposite())
            {
                PowerFrom = UnitWithMaxPower(_unitFrom->GetCompositeUnit()->GetUnits())->GetPower();
                HealthFrom = UnitWithMinHealth(_unitFrom->GetCompositeUnit()->GetUnits())->GetUnitsOfLife();
            }
            else
            {
                PowerFrom = _unitFrom->GetPower();
                HealthFrom = _unitFrom->GetUnitsOfLife();
            }

            Unit::Ptr _unitTo = _unitInfoTo->GetUnit();
            if (_unitTo->IsComposite())
            {
                PowerTo = UnitWithMaxPower(_unitTo->GetCompositeUnit()->GetUnits())->GetPower();
                HealthTo = UnitWithMinHealth(_unitTo->GetCompositeUnit()->GetUnits())->GetUnitsOfLife();
            }
            else
            {
                PowerTo = _unitTo->GetPower();
                HealthTo = _unitTo->GetUnitsOfLife();
            }

            int StepsCountHeroFrom = (HealthTo - 1)/PowerFrom + 1;
            int StepsCountHeroTo = (HealthFrom - 1)/PowerTo + 1;
            return StepsCountHeroFrom <= StepsCountHeroTo;

        });
        if (it != unitsInfoTo->end())
        {
            Unit::Ptr unit = _unitInfoFrom->GetUnit();
            if (unit->IsComposite())
            {
                unitFrom = UnitWithMaxPower(unit->GetCompositeUnit()->GetUnits());
            }
            else
            {
                unitFrom = unit;
            }

            if ((*it)->GetUnit()->IsComposite())
            {
                unitTo = UnitWithMinHealth((*it)->GetUnit()->GetCompositeUnit()->GetUnits());
            }
            else
            {
                unitTo = (*it)->GetUnit();
            }
            return true;
        }
    }

    return false;
}

bool Strategy1::GetStandaloneUnitToAttack(Hero &heroFrom, Hero &heroTo, Unit::Ptr &unitFrom,
                                               Unit::Ptr &unitTo)
{
    UnitInfo::CollectionPtr unitsInfoFrom = heroFrom.GetUnits();
    UnitInfo::CollectionPtr unitsInfoTo = heroTo.GetUnits();

    for (auto _unitInfoFrom : *unitsInfoFrom)
    {
        auto it = std::find_if(unitsInfoTo->begin(), unitsInfoTo->end(), [&_unitInfoFrom](const UnitInfo::Ptr &_unitInfoTo)
        {
            return AreNeighbours(_unitInfoFrom->GetPosition(), _unitInfoTo->GetPosition());
        });
        if (it != unitsInfoTo->end())
        {
            Unit::Ptr unit = _unitInfoFrom->GetUnit();
            if (unit->IsComposite())
            {
                unitFrom = UnitWithMaxPower(unit->GetCompositeUnit()->GetUnits());
            }
            else
            {
                unitFrom = unit;
            }

            if ((*it)->GetUnit()->IsComposite())
            {
                unitTo = UnitWithMinHealth((*it)->GetUnit()->GetCompositeUnit()->GetUnits());
            }
            else
            {
                unitTo = (*it)->GetUnit();
            }
            return true;
        }
    }

    return false;
}

bool Strategy1::GetUnitToMove(Hero &heroFrom, Hero &heroTo, UnitInfo::Ptr &unitInfoFrom, Direction &direction)
{
    UnitInfo::CollectionPtr unitsInfoFrom = heroFrom.GetUnits();
    UnitInfo::CollectionPtr unitsInfoTo = heroTo.GetUnits();

    int MinDistance = INT_MAX;

    for (auto _unitInfoFrom : *unitsInfoFrom)
    {
        if (unitsInfoTo->end() != std::find_if(unitsInfoTo->begin(), unitsInfoTo->end(), [&_unitInfoFrom](const UnitInfo::Ptr &_unitInfoTo)
        {
            return AreNeighbours(_unitInfoFrom->GetPosition(), _unitInfoTo->GetPosition());
        }))
        {
            continue;
        }

        std::vector<Direction> directions = {Right, Left, Up, Down};
        for (auto _direction : directions)
        {
            int distance = 0;
            Position _unitFromPosition;
            switch (_direction)
            {
                case Right:
                    _unitFromPosition =  _unitInfoFrom->GetPosition().Right();
                    break;
                case Left:
                    _unitFromPosition =  _unitInfoFrom->GetPosition().Left();
                    break;
                case Up:
                    _unitFromPosition =  _unitInfoFrom->GetPosition().Up();
                    break;
                case Down:
                    _unitFromPosition =  _unitInfoFrom->GetPosition().Down();
                    break;
                default:
                    throw InvalidDirectionException();
            }

            if (!BattleField::getInstance().IsFreePosition(_unitFromPosition))
                continue;

            for (auto _unitInfoTo : *unitsInfoTo)
            {
                distance += GetDistance(_unitFromPosition, _unitInfoTo->GetPosition());
            }

            if (distance < MinDistance)
            {
                MinDistance = distance;
                unitInfoFrom = _unitInfoFrom;
                direction = _direction;
            }
        }

    }

    return MinDistance < INT_MAX;
}

void Strategy1::ExecuteCommand(Command::Ptr command)
{
    command->execute();
}