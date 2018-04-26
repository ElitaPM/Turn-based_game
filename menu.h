#ifndef MENU_H
#define MENU_H
#include "field.h"
#include <iostream>
#include <iomanip>

class Menu
{
private:
    char field [41][84];
public:
    Menu();
    void print(Field &field);
    void print(Unit **blue_unit, Unit **yellow_unit, Unit* blue_base, Unit* yellow_base);
    void units_choise() const;
};

#endif // MENU_H
