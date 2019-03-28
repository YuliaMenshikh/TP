#include <iostream>
#include <vector>

#include "UnitFactory.h"
#include "Dungeon/DungeonFactory.h"
#include "Heaven/HeavenFactory.h"

int main()
{
    const int DungeonfactoryId = 1;
    const int HeavenFactoryId = 2;

    std::cout << "Select team:" << std::endl;
    std::cout << DungeonfactoryId << ": " << DungeonFactory::name() << std::endl;
    std::cout << HeavenFactoryId << ": " << HeavenFactory::name() << std::endl;

    int factoryId = 0;
    std::cin >> factoryId;
    UnitFactory* factory = nullptr;
    switch (factoryId)
    {
    case DungeonfactoryId:
        factory = new DungeonFactory;
        break;
    case HeavenFactoryId:
        factory = new HeavenFactory;
        break;
    default:
        std::cout << "Invalid team selected" << std::endl;
        return -1;
    }

    UnitFactory::UnitItems availableUnits;
    factory->GetAvailableUnits(availableUnits);

    std::vector<Unit*> units;
    int unitId = 0;
    while (true)
    {
        std::cout << std::endl;
        std::cout << "Select " << factory->GetName() << " unit:" << std::endl;
        std::cout << "0 - Select complete" << std::endl;
        for (size_t i = 0; i < availableUnits.size(); ++i)
        {
            std::cout << availableUnits[i].first << " - " << availableUnits[i].second << std::endl;
        }

        std::cin >> unitId;
        if (unitId == 0)
            break;

        Unit* unit = factory->CreateUnit(unitId);
        if (unit)
        {
            units.push_back(unit);
        }
        else
        {
            std::cout << "Invalid select" << std::endl;
        }
    };

    std::cout << std::endl;
    std::cout << factory->GetName() << " units:" << std::endl;
    for (size_t i = 0; i < units.size(); ++i)
    {
        std::cout << units[i]->GetName() << std::endl;
        delete units[i];
    }
    delete factory;
    //system("pause"); // Remove this
    return 0;
}
