#pragma once

#include "Strategy.h"
#include "Unit.h"

class SimpleStrategy : public Strategy
{
public:
    virtual void MakeStep(Hero::Ptr heroFrom, Hero::Ptr heroTo) override;

private:
    bool GetUnitToAttack(Hero::Ptr heroFrom, Hero::Ptr heroTo, Unit::Ptr &unitFrom, Unit::Ptr &unitTo) const;
    bool GetClosestUnits(Hero::Ptr heroFrom, Hero::Ptr heroTo, UnitInfo::Ptr &unitInfoFrom, UnitInfo::Ptr &unitInfoTo) const;
    bool CanMoveToward(const Position &positionFrom, const Position &positionTo) const;
};