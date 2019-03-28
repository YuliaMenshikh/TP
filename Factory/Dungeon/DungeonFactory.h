#pragma once

#include "UnitFactory.h"

class DungeonFactory : public UnitFactory
{
public:
    virtual void GetAvailableUnits(UnitItems& units) const override;
    virtual Unit* CreateUnit(int unitId) const override;
    virtual std::string GetName() const { return name(); }

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
