#include "HeavenFactory.h"
#include "DuncanSingleton.h"
#include "Angel.h"
#include "Archer.h"
#include "Cavalier.h"
#include "Footman.h"
#include "Griffin.h"
#include "Peasant.h"
#include "Priest.h"
#include "Exceptions.h"

#include <memory>

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

Hero::Ptr HeavenFactory::CreateHero() const
{
    return std::make_shared<Duncan>();
}

Unit::Ptr HeavenFactory::CreateUnit(int unitId) const
{
    switch (unitId)
    {
        case HeavenAngel:
            return std::make_shared<Angel>();
        case HeavenArcher:
            return std::make_shared<Archer>();
        case HeavenCavalier:
            return std::make_shared<Cavalier>();
        case HeavenFootman:
            return std::make_shared<Footman>();
        case HeavenGriffin:
            return std::make_shared<Griffin>();
        case HeavenPeasant:
            return std::make_shared<Peasant>();
        case HeavenPriest:
            return std::make_shared<Priest>();
    }
    throw InvalidUnitIdException();
}
