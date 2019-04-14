#pragma once

#include "HeroBase.h"
#include "Unit.h"

class Ylaya : public HeroBase
{
public:
    static Ylaya& getInstance()
    {
        static Ylaya instance;
        return instance;
    }

    virtual std::string GetName() const override
    {
        return "Ylaya";
    }

private:
    Ylaya() {}
    Ylaya(const Ylaya&);
    Ylaya& operator = (Ylaya&);
};
