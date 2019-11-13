#pragma once

#include "Logger.h"
#include <fstream>

class FileLogger : public Logger
{
public:
    FileLogger() : _outfile("game.log", std::ios::out | std::ios::trunc) {}
    virtual void Write(const std::string &message)
    {
        if (_outfile.is_open())
        {
            _outfile << message;
        }
    }

private:
    std::ofstream _outfile;
};