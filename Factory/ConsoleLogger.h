#pragma once

#include "Logger.h"

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger() {}
    virtual void Write(const std::string &message)
    {
        std::cout << message;
    }
};