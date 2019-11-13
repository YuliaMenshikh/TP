#pragma once

#include <iostream>

class Position
{
public:
    Position() : _x(0), _y(0)
    {
    }
    Position(int x, int y) : _x(x), _y(y)
    {
    }
    int GetX() const
    {
        return _x;
    }
    int GetY() const
    {
        return _y;
    }
    Position Right() const
    {
        return Position(_x + 1, _y);
    }
    Position Left() const
    {
        return Position(_x - 1, _y);
    }
    Position Up() const
    {
        return Position(_x, _y + 1);
    }
    Position Down() const
    {
        return Position(_x, _y - 1);
    }

    bool operator<(const Position &position) const
    {
        if (_x < position.GetX())
            return true;
        if (_x > position.GetX())
            return false;
        if (_y < position.GetY())
            return true;
        return false;
    }

    bool operator==(const Position &position) const
    {
        return _x == position.GetX() && _y == position.GetY();
    }

private:
    int _x;
    int _y;
};

inline int GetDistance(const Position &position1, const Position &position2)
{
    return std::abs(position1.GetX() - position2.GetX()) + std::abs(position1.GetY() - position2.GetY());
}

inline bool AreNeighbours(const Position &position1, const Position &position2)
{
    if (GetDistance(position1, position2) < 2)
        return true;
    return false;
}