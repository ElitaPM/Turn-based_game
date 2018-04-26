#ifndef WARBASE_H
#define WARBASE_H
#include "unit.h"

class WarBase: public Unit
{
private:
    bool Cooldown;
    std::string color;
public:
    WarBase(std::string color): Unit(color)
    {
        HP = 500;
        armor = 5;
        unit_name = "Военная база";
    }
    bool ability() {}
    bool bonus(){}
};

#endif // WARBASE_H
