#include "DungeonFactory.h"
#include "BloodMaiden.h"
#include "DarkRaiden.h"
#include "Hydra.h"
#include "Minotaur.h"
#include "Scout.h"
#include "ShadowWitch.h"
#include "ShadowDragon.h"

void DungeonFactory::GetAvailableUnits(UnitItems& units) const
{
    units.clear();
    units.push_back(UnitItem(DungeonScout, Scout::name()));
    units.push_back(UnitItem(DungeonBloodMaiden, BloodMaiden::name()));
    units.push_back(UnitItem(DungeonMinotaur, Minotaur::name()));
    units.push_back(UnitItem(DungeonDarkRaiden, DarkRaiden::name()));
    units.push_back(UnitItem(DungeonHydra, Hydra::name()));
    units.push_back(UnitItem(DungeonShadowWitch, ShadowWitch::name()));
    units.push_back(UnitItem(DungeonShadowDragon, ShadowDragon::name()));
}

Unit* DungeonFactory::CreateUnit(int unitId) const
{
    switch (unitId)
    {
        case DungeonScout:
            return new Scout;
        case DungeonBloodMaiden:
            return new BloodMaiden;
        case DungeonMinotaur:
            return new Minotaur;
        case DungeonDarkRaiden:
            return new DarkRaiden;
        case DungeonHydra:
            return new Hydra;
        case DungeonShadowWitch:
            return new ShadowWitch;
        case DungeonShadowDragon:
            return new ShadowDragon;
    }

    return nullptr;
}
