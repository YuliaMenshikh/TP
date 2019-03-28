#include "HeavenFactory.h"
#include "Angel.h"
#include "Archer.h"
#include "Cavalier.h"
#include "Footman.h"
#include "Griffin.h"
#include "Peasant.h"
#include "Priest.h"

void HeavenFactory::GetAvailableUnits(UnitItems& units) const
{
    units.clear();
    units.push_back(UnitItem(HeavenAngel, Angel::name()));
    units.push_back(UnitItem(HeavenArcher, Archer::name()));
    units.push_back(UnitItem(HeavenCavalier, Cavalier::name()));
    units.push_back(UnitItem(HeavenFootman, Footman::name()));
    units.push_back(UnitItem(HeavenGriffin, Griffin::name()));
    units.push_back(UnitItem(HeavenPeasant, Peasant::name()));
    units.push_back(UnitItem(HeavenPriest, Priest::name()));
}

Unit* HeavenFactory::CreateUnit(int unitId) const
{
    switch (unitId)
    {
        case HeavenAngel:
            return new Angel;
        case HeavenArcher:
            return new Archer;
        case HeavenCavalier:
            return new Cavalier;
        case HeavenFootman:
            return new Footman;
        case HeavenGriffin:
            return new Griffin;
        case HeavenPeasant:
            return  new Peasant;
        case HeavenPriest:
            return new Priest;
    }

    return nullptr;
}
