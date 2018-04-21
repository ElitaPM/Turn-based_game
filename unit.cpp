#include "unit.h"

Unit::Unit()
{

}

void Unit::set_coord(int first, int second)
{
    this->coord.first = first;
    this->coord.second = second;
}

std::pair<int, int> Unit::get_coord()
{
    return this->coord;
}
