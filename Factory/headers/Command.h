#pragma once

#include "UnitInfo.h"
#include "Direction.h"
#include "Hero.h"
#include <memory>

class Command
{
public:
    typedef std::shared_ptr<Command> Ptr;

    virtual ~Command() {}
    virtual void execute() = 0;
};

class AttackCommand : public Command
{
public:
    AttackCommand(Unit::Ptr unitFrom, Hero &heroTo, Unit::Ptr unitTo);
    virtual void execute() override;

private:
    Unit::Ptr _unitFrom;
    Hero &_heroTo;
    Unit::Ptr _unitTo;
};

class MoveCommand : public Command
{
public:
    MoveCommand(UnitInfo::Ptr unitInfo, Direction direction);
    virtual void execute() override;

private:
    Direction _direction;
    UnitInfo::Ptr _unitInfo;
};