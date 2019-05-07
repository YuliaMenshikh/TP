#pragma once

#include <string>
#include <memory>

class Logger
{
public:
    typedef std::shared_ptr<Logger> Ptr;

    Logger() {}
    static Logger& getInstance();

    virtual void Write(const std::string &message) = 0;

private:
    Logger(const Logger&);
    Logger& operator=(const Logger&);
};
