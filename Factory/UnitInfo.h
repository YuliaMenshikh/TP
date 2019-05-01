#pragma once

#include "Position.h"
#include "Unit.h"
#include "Direction.h"
#include <vector>
#include <memory>

class UnitInfo
{
public:
    typedef std::shared_ptr<UnitInfo> Ptr;
    typedef std::vector<Ptr> Collection;
    typedef std::shared_ptr<Collection> CollectionPtr;

    UnitInfo(Unit::Ptr unit, Position position);
    UnitInfo(const UnitInfo&) = delete;
    UnitInfo& operator=(const UnitInfo&) = delete;
    ~UnitInfo();

    Unit::Ptr GetUnit() const;
    const Position& GetPosition() const;
    void Move(Direction direction);

private:
    Unit::Ptr _unit;
    Position _position;
};