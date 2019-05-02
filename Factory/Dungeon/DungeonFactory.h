#pragma once

#include "UnitFactory.h"

class DungeonFactory : public UnitFactory
{
public:
    virtual void GetAvailableUnits(UnitItems& units) const override;
    virtual Hero::Ptr CreateHero(Strategy::Ptr strategy) const override;
    virtual Unit::Ptr CreateUnit(int unitId) const override;
    virtual std::string GetName() const override { return name(); }

    static std::string name() { return "Dungeon"; }

    enum UNITS
    {
        DungeonScout = 1,
        DungeonBloodMaiden,
        DungeonMinotaur,
        DungeonDarkRaiden,
        DungeonHydra,
        DungeonShadowWitch,
        DungeonShadowDragon
    };
};
