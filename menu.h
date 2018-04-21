#ifndef MENU_H
#define MENU_H
#include "field.h"
#include <iostream>

class Menu
{
private:
    char field [41][82];
public:
    Menu();
    void print(Field &field);
    void print();
};

#endif // MENU_H
