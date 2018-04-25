#ifndef WARBASE_H
#define WARBASE_H
#include "unit.h"

class WarBase: public Unit
{
private:
    bool Cooldown;
    std::string color;
public:
    WarBase(std::string color): Unit(color){}
    bool ability() {}
    bool is_alive() {}
    void bonus(){}
};

#endif // WARBASE_H
