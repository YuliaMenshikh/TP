#pragma once

#include "Unit.h"
#include "UnitInfo.h"
#include <vector>
#include <string>

class Squad : public Unit
{
public:
    Squad(const std::string &name);
    void AddUnit(Unit::Ptr unit, const Position &position);

    virtual std::string GetName() const override;
    virtual int GetPower() const override;
    virtual int GetProtection() const override;
    virtual int GetUnitsOfLife() const override;
    virtual int GetInitiative() const override;
    virtual int GetSpeed() const override;
    virtual int GetStockShots() const override;
    virtual int GetMagicPoints() const override;

private:
    std::string _name;
    UnitInfo::Collection _units;
};
