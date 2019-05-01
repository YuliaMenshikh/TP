#include "SimpleStrategy.h"
#include "BattleField.h"

#include<algorithm>

void SimpleStrategy::MakeStep(Hero::Ptr heroFrom, Hero::Ptr heroTo)
{
    Unit::Ptr unitFrom;
    Unit::Ptr unitTo;

    if(GetUnitToAttack(heroFrom, heroTo, unitFrom, unitTo))
    {
        unitTo->DecreaseUnitsOfLfe(unitFrom->GetPower());
        std::cout << unitFrom->GetName() << " атаковал " << unitTo->GetName() << std::endl;
        heroTo->RemoveDied();
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
            unitInfoFrom->Move(Right);
            moved = true;
        }
        else if (positionFrom.GetX() > positionTo.GetX() && BattleField::getInstance().IsFreePosition(positionFrom.Left()))
        {
            unitInfoFrom->Move(Left);
            moved = true;
        }
        else if(positionFrom.GetY() < positionTo.GetY() && BattleField::getInstance().IsFreePosition(positionFrom.Up()))
        {
            unitInfoFrom->Move(Up);
            moved = true;
        }
        else if(positionFrom.GetY() > positionTo.GetY() && BattleField::getInstance().IsFreePosition(positionFrom.Down()))
        {
            unitInfoFrom->Move(Down);
            moved = true;
        }
    }

    if (moved)
    {
        std::cout << unitInfoFrom->GetUnit()->GetName() << " сделал шаг по направлению к " << unitInfoTo->GetUnit()->GetName()
        << " на позицию (" << unitInfoFrom->GetPosition().GetX() << ", " << unitInfoFrom->GetPosition().GetY() << ")" << std::endl;
    }
    else
    {
        std::cout << "Армии героя "<< heroFrom->GetName() <<" некого двигать" << std::endl;
    }
}

bool SimpleStrategy::GetUnitToAttack(Hero::Ptr heroFrom, Hero::Ptr heroTo, Unit::Ptr &unitFrom, Unit::Ptr &unitTo) const
{
    UnitInfo::CollectionPtr unitsInfoFrom = heroFrom->GetUnits();
    UnitInfo::CollectionPtr unitsInfoTo = heroTo->GetUnits();

    for (auto _unitInfoFrom : *unitsInfoFrom)
    {
        auto it = std::find_if(unitsInfoTo->begin(), unitsInfoTo->end(), [&_unitInfoFrom](const UnitInfo::Ptr &_unitInfoTo)
        {
            return AreNeighbours(_unitInfoFrom->GetPosition(), _unitInfoTo->GetPosition());
        });
        if (it != unitsInfoTo->end())
        {
            unitFrom = _unitInfoFrom->GetUnit();
            unitTo = (*it)->GetUnit();
            return true;
        }
    }

    return false;
}

bool SimpleStrategy::CanMoveToward(const Position &positionFrom, const Position &positionTo) const
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

bool SimpleStrategy::GetClosestUnits(Hero::Ptr heroFrom, Hero::Ptr heroTo, UnitInfo::Ptr &unitInfoFrom, UnitInfo::Ptr &unitInfoTo) const
{
    UnitInfo::CollectionPtr unitsInfoFrom = heroFrom->GetUnits();
    UnitInfo::CollectionPtr unitsInfoTo = heroTo->GetUnits();

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




