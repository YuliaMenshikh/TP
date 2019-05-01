#include <exception>

class InvalidFactoryIdException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Invalid factory id";
    }
};

class InvalidUnitIdException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Invalid unit id";
    }
};

class PositionIsTaken : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Position is taken";
    }
};

class InvalidDirection : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Invalid direction";
    }
};

