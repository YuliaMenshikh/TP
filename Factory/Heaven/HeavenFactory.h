#pragma once

#include "UnitFactory.h"

class HeavenFactory : public UnitFactory
{
public:
    virtual void GetAvailableUnits(UnitItems& units) const override;
    virtual Hero::Ptr CreateHero() const override;
    virtual Unit::Ptr CreateUnit(int unitId) const override;
    virtual std::string GetName() const override { return name(); }

    static std::string name() { return "Heaven"; }

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
