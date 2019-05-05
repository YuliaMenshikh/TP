#pragma once

#include "Unit.h"
#include <vector>
#include <string>

class Squad : public Unit, public CompositeUnit
{
public:
    Squad(const std::string &name);
    void AddUnit(Unit::Ptr unit);

    virtual bool IsComposite() const override;
    virtual CompositeUnit* GetCompositeUnit() override;
    virtual StandaloneUnit* GetStandAloneUnit() override;

    virtual std::string GetName() const override;
    virtual int GetPower() const override;
    virtual int GetProtection() const override;
    virtual int GetUnitsOfLife() const override;
    virtual int GetInitiative() const override;
    virtual int GetSpeed() const override;
    virtual int GetStockShots() const override;
    virtual int GetMagicPoints() const override;

    virtual Unit::CollectionPtr GetUnits() const override;

    virtual bool IsAlive() const override;

    virtual void RemoveDied() override;

private:
    std::string _name;
    Unit::CollectionPtr _units;
};
