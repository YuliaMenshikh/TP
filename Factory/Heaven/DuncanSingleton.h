#pragma once

#include "HeroBase.h"
#include "Unit.h"

class Duncan : public HeroBase
{
public:
    static Duncan& getInstance()
    {
        static Duncan instance;
        return instance;
    }

    virtual std::string GetName() const override
    {
        return "Duncan";
    }

private:
    Duncan() {}
    Duncan(const Duncan& );
    Duncan& operator = (Duncan&);
};
