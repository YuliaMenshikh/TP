#include <exception>

class InvalidFactoryIdException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "InvalidFactoryIdException";
    }
};

class InvalidUnitIdException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "InvalidUnitIdException";
    }
};

