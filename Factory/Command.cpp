#include "Command.h"

AttackCommand::AttackCommand(Unit::Ptr unitFrom, Hero &heroTo, Unit::Ptr unitTo) :
                            _unitFrom(unitFrom), _heroTo(heroTo), _unitTo(unitTo)
{
}

void AttackCommand::execute()
{
    _unitTo->GetStandAloneUnit()->DecreaseUnitsOfLife(_unitFrom->GetPower());
    _heroTo.RemoveDied();
}

MoveCommand::MoveCommand(UnitInfo::Ptr unitInfo, Direction direction) : _unitInfo(unitInfo), _direction(direction) {}

void MoveCommand::execute()
{
    _unitInfo->Move(_direction);
}