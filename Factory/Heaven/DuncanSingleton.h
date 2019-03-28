#pragma once

class Duncan
{
public:
    static Duncan& getInstance() {
        static Duncan  instance;
        return instance;
    }
private:
    Duncan() {}
    Duncan(const Duncan& );
    Duncan& operator = (Duncan&);

    int _level;
    int _power;
    int _protection;
    int _magicPoints;
    int  _knowledge;

};
