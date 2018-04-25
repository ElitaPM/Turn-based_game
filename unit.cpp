#include "unit.h"


void Unit::set_coord(int first, int second)
{
    this->coord.first = first;
    this->coord.second = second;
}

std::pair<int, int> Unit::get_coord()
{
    return this->coord;
}


std::string Unit::get_unit_name()
{
    return unit_name;
}
