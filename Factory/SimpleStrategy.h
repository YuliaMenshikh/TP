#pragma once

#include "Strategy.h"
#include "Unit.h"

class SimpleStrategy : public Strategy
{
public:
    virtual void MakeStep(Hero &heroFrom, Hero &heroTo) override;

private:
    static bool GetStandaloneUnitToAttack(Hero &heroFrom, Hero &heroTo, Unit::Ptr &unitFrom, Unit::Ptr &unitTo);
    static bool GetClosestUnits(Hero &heroFrom, Hero &heroTo, UnitInfo::Ptr &unitInfoFrom, UnitInfo::Ptr &unitInfoTo);
    static bool CanMoveToward(const Position &positionFrom, const Position &positionTo);
};