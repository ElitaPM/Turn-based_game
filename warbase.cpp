#include "warbase.h"


void WarBase::ability(Unit** some_units, Unit* base)
{
    std::cout << "Состояние неуязвимости " << std::endl;
    some_units[0]->set_armor(10);
    some_units[1]->set_armor(10);
    some_units[2]->set_armor(10);
    base->set_armor(10);
}
