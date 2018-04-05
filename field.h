#ifndef FIELD_H
#define FIELD_H
#include "unit.h"
#include "barrier.h"
#include "soldier.h"
#include "warbase.h"

class Field
{
private:
    Unit *ptr[20][20];
public:
    Field();
    void move(Soldier &soldier);
};

#endif // FIELD_H
