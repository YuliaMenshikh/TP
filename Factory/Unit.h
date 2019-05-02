#pragma once

#include "Position.h"

#include <string>
#include <memory>
#include <vector>

struct CompositeUnit;
struct StandaloneUnit;

struct Unit
{
    typedef std::shared_ptr<Unit> Ptr;
    typedef std::vector<Ptr> Collection;
    typedef std::shared_ptr<Collection> CollectionPtr;

    virtual ~Unit() {}

    virtual bool IsComposite() const = 0;
    virtual CompositeUnit* GetCompositeUnit() = 0;
    virtual StandaloneUnit* GetStandAloneUnit() = 0;

    virtual std::string GetName() const = 0;
    virtual int GetPower() const = 0;
    virtual int GetProtection() const = 0;
    virtual int GetUnitsOfLife() const = 0;
    virtual int GetInitiative() const = 0;
    virtual int GetSpeed() const = 0;
    virtual int GetStockShots() const = 0;
    virtual int GetMagicPoints() const = 0;
    virtual bool IsAlive() const = 0;
    /*
    //composite
    virtual Unit::CollectionPtr GetUnits() const = 0;
    virtual void RemoveDied() = 0;

    //alone
    virtual void DecreaseUnitsOfLife(int) = 0;
     */
};

struct CompositeUnit
{
    virtual Unit::CollectionPtr GetUnits() const = 0;
    virtual void RemoveDied() = 0;
};

struct StandaloneUnit
{
    virtual void DecreaseUnitsOfLife(int) = 0;
};
