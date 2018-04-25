#ifndef FIELD_H
#define FIELD_H
#include "unit.h"
#include "barrier.h"
#include "soldier.h"
#include "warbase.h"
#include <typeinfo>
#include <vector>
#include <iostream>

class Field
{
private:
    Unit *ptr[20][20];
public:
    Field();
    bool hit(Unit* soldier, int range);
    void move(Unit* soldier);
    void shoot(Unit* soldier);
    void units_simbol(char **symbols);
    void init(Unit* blueUnit_1,
              Unit* blueUnit_2,
              Unit* blueUnit_3,
              Unit* yellowUnit_1,
              Unit* yellowUnit_2,
              Unit* yellowUnit_3,
              WarBase& blueWarBase,
              WarBase& yellowWarBase,
              Barrier& barrier);


};

#endif // FIELD_H
