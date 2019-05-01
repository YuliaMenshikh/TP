#include <iostream>
#include "BattleField.h"
#include "Exceptions.h"

bool BattleField::IsFreePosition(const Position &position) const
{
    return _takenPositions.find(position) == _takenPositions.end();
}

void BattleField::TakePosition(const Position &position)
{
    if (!IsFreePosition(position))
        throw PositionIsTakenException();

    _takenPositions.insert(position);
}

void BattleField::FreePosition(const Position &position)
{
    _takenPositions.erase(position);
}

