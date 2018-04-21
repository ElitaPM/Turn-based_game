#ifndef FIELD_H
#define FIELD_H
#include "unit.h"
#include "barrier.h"
#include "soldier.h"
#include "warbase.h"
#include <typeinfo>
#include <vector>

class Field
{
private:
    Unit *ptr[20][20];
public:
    Field();
    void move(Unit *soldier);
    void units_simbol(std::vector<std::vector<char> > &vec);
    void init(Unit* yellowUnit_1,
              Unit* yellowUnit_2,
              Unit* yellowUnit_3,
              Unit* blueUnit_1,
              Unit* blueUnit_2,
              Unit* blueUnit_3,
              WarBase& blueWarBase,
              WarBase& yellowWarBase,
              Barrier& barrier);
};

#endif // FIELD_H
