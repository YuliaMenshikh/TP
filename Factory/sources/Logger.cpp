#include "Logger.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"

Logger& Logger::getInstance()
{
    static Logger::Ptr instance(new ConsoleLogger());
    return *instance;
}