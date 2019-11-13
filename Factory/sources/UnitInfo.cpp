#include "UnitInfo.h"
#include "BattleField.h"
#include "Exceptions.h"

UnitInfo::UnitInfo(Unit::Ptr unit, Position position) : _unit(unit), _position(position)
{
    BattleField::getInstance().TakePosition(_position);
}

UnitInfo::~UnitInfo()
{
    BattleField::getInstance().FreePosition(_position);
}

Unit::Ptr UnitInfo::GetUnit() const
{
    return _unit;
}

const Position& UnitInfo::GetPosition() const
{
    return _position;
}

void UnitInfo::Move(Direction direction)
{
    BattleField::getInstance().FreePosition(_position);
    switch (direction)
    {
        case Right:
            _position =  _position.Right();
            break;
        case Left:
            _position =  _position.Left();
            break;
        case Up:
            _position =  _position.Up();
            break;
        case Down:
            _position =  _position.Down();
            break;
        default:
            throw InvalidDirectionException();
    }
    BattleField::getInstance().TakePosition(_position);
}