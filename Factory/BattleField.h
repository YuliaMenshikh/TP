#pragma once

#include "Position.h"

#include <set>

class BattleField
{
public:
    static BattleField& getInstance()
    {
        static BattleField instance;
        return instance;
    }

    bool IsFreePosition(const Position &position) const;
    void TakePosition(const Position &position);
    void FreePosition(const Position &position);

private:
    BattleField() {}
    BattleField(const BattleField&);
    BattleField& operator=(BattleField&);

    std::set<Position> _takenPositions;
};

