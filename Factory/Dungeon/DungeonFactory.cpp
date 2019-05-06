#include "DungeonFactory.h"
#include "YlayaHero.h"
#include "BloodMaiden.h"
#include "DarkRaiden.h"
#include "Hydra.h"
#include "Minotaur.h"
#include "Scout.h"
#include "ShadowWitch.h"
#include "ShadowDragon.h"
#include "Exceptions.h"
#include "UnitDecorator.h"

#include <memory>

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

Hero::Ptr DungeonFactory::CreateHero(Strategy::Ptr strategy) const
{
    return std::make_shared<Ylaya>(strategy);
}

Unit::Ptr DungeonFactory::CreateUnit(int unitId) const
{
    switch (unitId)
    {
        case DungeonScout:
            return std::make_shared<Scout>();
        case DungeonBloodMaiden:
            return std::make_shared<BloodMaiden>();
        case DungeonMinotaur:
            return std::make_shared<Minotaur>();
        case DungeonDarkRaiden:
            return std::make_shared<DarkRaiden>();
        case DungeonHydra:
            return std::make_shared<Hydra>();
        case DungeonShadowWitch:
            return std::make_shared<ShadowWitch>();
        case DungeonShadowDragon:
            return std::make_shared<ShadowDragon>();
    }
    throw InvalidUnitIdException();
}
