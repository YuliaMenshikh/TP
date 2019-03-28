#pragma once

class Ylaya
{
private:
    Ylaya() {}
    Ylaya(const Ylaya& );
    Ylaya& operator = (Ylaya&);
public:
    static Ylaya& getInstance() {
        static Ylaya  instance;
        return instance;
    }
};
