#include "SimpleStrategy.h"
#include "BattleField.h"
#include "Exceptions.h"
#include "Logger.h"

#include <algorithm>
#include <climits>
#include <sstream>

void SimpleStrategy::MakeStep(Hero &heroFrom, Hero &heroTo)
{
    Unit::Ptr unitFrom;
    Unit::Ptr unitTo;

    if (GetStandaloneUnitToAttack(heroFrom, heroTo, unitFrom, unitTo))
    {
        Logger::getInstance().Write(unitFrom->GetName() + " attacked " + unitTo->GetName() + "\n");
        ExecuteCommand(Command::Ptr(new AttackCommand(unitFrom, heroTo, unitTo)));
        return;
    }

    UnitInfo::Ptr unitInfoFrom;
    UnitInfo::Ptr unitInfoTo;

    bool moved = false;

    if (GetClosestUnits(heroFrom, heroTo, unitInfoFrom, unitInfoTo))
    {
        const Position &positionFrom = unitInfoFrom->GetPosition();
        const Position &positionTo = unitInfoTo->GetPosition();

        if (positionFrom.GetX() < positionTo.GetX() && BattleField::getInstance().IsFreePosition(positionFrom.Right()))
        {
            ExecuteCommand(Command::Ptr(new MoveCommand(unitInfoFrom, Right)));
            moved = true;
        }
        else if (positionFrom.GetX() > positionTo.GetX() && BattleField::getInstance().IsFreePosition(positionFrom.Left()))
        {
            ExecuteCommand(Command::Ptr(new MoveCommand(unitInfoFrom, Left)));
            moved = true;
        }
        else if(positionFrom.GetY() < positionTo.GetY() && BattleField::getInstance().IsFreePosition(positionFrom.Up()))
        {
            ExecuteCommand(Command::Ptr(new MoveCommand(unitInfoFrom, Up)));
            moved = true;
        }
        else if(positionFrom.GetY() > positionTo.GetY() && BattleField::getInstance().IsFreePosition(positionFrom.Down()))
        {
            ExecuteCommand(Command::Ptr(new MoveCommand(unitInfoFrom, Down)));
            moved = true;
        }
    }

    if (moved)
    {
        std::ostringstream oss;
        oss << unitInfoFrom->GetUnit()->GetName() << " took a step towards the " << unitInfoTo->GetUnit()->GetName()
            << " to position (" << unitInfoFrom->GetPosition().GetX() << ", " << unitInfoFrom->GetPosition().GetY() << ")" << "\n";
        Logger::getInstance().Write(oss.str());
    }
    else
    {
        Logger::getInstance().Write(heroFrom.GetName() + "'s army no one to move\n");
    }
}

Unit::Ptr GetUnitWithMaxPower(Unit::CollectionPtr units)
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

Unit::Ptr GetUnitWithMinHealth(Unit::CollectionPtr units)
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

bool SimpleStrategy::GetStandaloneUnitToAttack(Hero &heroFrom, Hero &heroTo, Unit::Ptr &unitFrom,
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
                unitFrom = GetUnitWithMaxPower(unit->GetCompositeUnit()->GetUnits());
            }
            else
            {
                unitFrom = unit;
            }

            if ((*it)->GetUnit()->IsComposite())
            {
                unitTo = GetUnitWithMinHealth((*it)->GetUnit()->GetCompositeUnit()->GetUnits());
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

bool SimpleStrategy::CanMoveToward(const Position &positionFrom, const Position &positionTo)
{
    if (positionFrom.GetX() < positionTo.GetX() && BattleField::getInstance().IsFreePosition(positionFrom.Right()))
        return true;

    if (positionFrom.GetX() > positionTo.GetX() && BattleField::getInstance().IsFreePosition(positionFrom.Left()))
        return true;

    if(positionFrom.GetY() < positionTo.GetY() && BattleField::getInstance().IsFreePosition(positionFrom.Up()))
        return true;

    if (positionFrom.GetY() > positionTo.GetY() && BattleField::getInstance().IsFreePosition(positionFrom.Down()))
        return true;

    return false;
}

bool SimpleStrategy::GetClosestUnits(Hero &heroFrom, Hero &heroTo, UnitInfo::Ptr &unitInfoFrom, UnitInfo::Ptr &unitInfoTo)
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

        for (auto _unitInfoTo : *unitsInfoTo)
        {
            int distance = GetDistance(_unitInfoFrom->GetPosition(), _unitInfoTo->GetPosition());
            if (distance < MinDistance && CanMoveToward(_unitInfoFrom->GetPosition(), _unitInfoTo->GetPosition()))
            {
                unitInfoFrom = _unitInfoFrom;
                unitInfoTo = _unitInfoTo;
                MinDistance = distance;
            }
        }
    }

   return MinDistance < INT_MAX;
}

void SimpleStrategy::ExecuteCommand(Command::Ptr command)
{
    command->execute();
}




