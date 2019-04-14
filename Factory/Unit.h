#pragma once

#include <string>
#include <memory>

struct Unit
{
    typedef std::shared_ptr<Unit> Ptr;

    virtual ~Unit() {}
    virtual std::string GetName() const = 0;
    virtual int GetPower() const = 0;
    virtual int GetProtection() const = 0;
    virtual int GetUnitsOfLife() const = 0;
    virtual int GetInitiative() const = 0;
    virtual int GetSpeed() const = 0;
    virtual int GetStockShots() const = 0;
    virtual int GetMagicPoints() const = 0;
};
