#pragma once

#include "UnitFactory.h"

class DungeonFactory : public UnitFactory
{
public:
    virtual void GetAvailableUnits(UnitItems& units) const override;
    virtual Hero& GetHero() const override;
    virtual Unit::Ptr CreateUnit(int unitId) const override;
    virtual std::string GetName() const override { return name(); }

    static std::string name() { return "Dungeon"; }

private:
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
