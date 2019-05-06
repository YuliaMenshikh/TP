#pragma once

#include "Logger.h"
#include <fstream>

class FileLogger : public Logger
{
public:
    FileLogger(Logger::Ptr logger)
    {
        out.open("output.txt");
    }
    virtual void Write(const std::string &message)
    {
        if (out.is_open())
        {
            out << message;
        }
    }

private:
    std::ofstream out;
};