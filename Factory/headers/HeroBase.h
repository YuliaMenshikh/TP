#pragma once

#include "Hero.h"
#include "BattleField.h"
#include "Strategy.h"

#include <vector>
#include <memory>

class HeroBase : public Hero
{
public:
    HeroBase(Strategy::Ptr strategy);
    HeroBase(const HeroBase&) = delete;
    HeroBase& operator = (const HeroBase&) = delete;

    virtual void MakeStep(Hero &heroTo) override;
    virtual UnitInfo::CollectionPtr GetUnits() const override;
    virtual void AddUnit(Unit::Ptr unit, const Position &position) override;
    virtual void RemoveDied() override;
    virtual bool HasUnits() const override;

private:
    Strategy::Ptr _strategy;
    UnitInfo::CollectionPtr _units;
};
