#pragma once

#include "Strategy.h"
#include "Unit.h"
#include "Command.h"

class Strategy1 : public Strategy
{
public:
    virtual void MakeStep(Hero &heroFrom, Hero &heroTo) override;

private:
    static bool GetStandaloneUnitToAttackAndKill(Hero &heroFrom, Hero &heroTo, Unit::Ptr &unitFrom, Unit::Ptr &unitTo);
    static bool GetStandaloneUnitToAttack(Hero &heroFrom, Hero &heroTo, Unit::Ptr &unitFrom, Unit::Ptr &unitTo);
    static bool GetUnitToMove(Hero &heroFrom, Hero &heroTo, UnitInfo::Ptr &unitInfoFrom, Direction &direction);

    static void ExecuteCommand(Command::Ptr command);
};