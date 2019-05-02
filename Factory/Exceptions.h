#include <exception>
#include <string>

class GameException : public std::exception
{
public:
    GameException(const std::string &what) : _what(what) {}
    virtual const char* what() const noexcept
    {
        return _what.c_str();
    }

private:
    const std::string _what;
};

class InvalidFactoryIdException : public GameException
{
public:
    InvalidFactoryIdException() : GameException("Invalid factory id") {}
};

class InvalidUnitIdException : public GameException
{
public:
    InvalidUnitIdException() : GameException("Invalid unit id") {}
};

class PositionIsTakenException : public GameException
{
public:
    PositionIsTakenException() : GameException("Position is taken") {}
};

class InvalidDirectionException : public GameException
{
public:
    InvalidDirectionException() : GameException("Invalid direction") {}
};

class NotImplementedException : public GameException
{
public:
    NotImplementedException() : GameException("Not implemented") {}
};
