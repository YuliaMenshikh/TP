#pragma once

#include "Position.h"

#include <string>
#include <memory>
#include <vector>

struct Unit
{
    typedef std::shared_ptr<Unit> Ptr;
    typedef std::vector<Ptr> Collection;
    typedef std::shared_ptr<Collection> CollectionPtr;

    virtual ~Unit() {}

    virtual bool IsComposite() const = 0;

    virtual std::string GetName() const = 0;
    virtual int GetPower() const = 0;
    virtual int GetProtection() const = 0;
    virtual int GetUnitsOfLife() const = 0;
    virtual int GetInitiative() const = 0;
    virtual int GetSpeed() const = 0;
    virtual int GetStockShots() const = 0;
    virtual int GetMagicPoints() const = 0;
    virtual Unit::CollectionPtr GetUnits() const = 0;

    virtual void DecreaseUnitsOfLife(int) = 0;

    virtual bool IsAlive() const = 0;

    virtual void RemoveDied() = 0;
};
