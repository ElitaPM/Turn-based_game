#ifndef WARBASE_H
#define WARBASE_H
#include "unit.h"

class WarBase: public Unit
{
private:
    bool Cooldown;
public:
    WarBase(): Unit(){}
    bool ability();
    bool is_alive();

};

#endif // WARBASE_H
