#pragma once

#include "UnitFactory.h"

class HeavenFactory : public UnitFactory
{
public:
    virtual void GetAvailableUnits(UnitItems& units) const override;
    virtual Unit* CreateUnit(int unitId) const override;
    virtual std::string GetName() const { return name(); }

    static std::string name() { return "Heaven"; }

private:
    enum UNITS
    {
        HeavenAngel = 1,
        HeavenArcher,
        HeavenCavalier,
        HeavenFootman,
        HeavenGriffin,
        HeavenPeasant,
        HeavenPriest
    };
};
