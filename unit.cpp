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

void Unit::showHP ()
{
    if(HP > 0)
        std::cout << HP;
    else
        std::cout << "Юнит мертв";
}

void Unit::before()
{
    if (this->get_unit_name() == "Автоматчик")
    {
        this->bonus();
//            std::cout << "Критический урон." << std::endl;
    }
    if (this->get_unit_name() == "Дробовик")
    {
        this->bonus();
    }
}

void Unit::non_bonus()
{
    if (this->get_unit_name() == "Автоматчик")
    {
        Weapon_damage = 20;
    }
    if (this->get_unit_name() == "Дробовик")
    {
        Weapon_damage = 200;
    }
}

int Unit::after()
{
    if (this->get_unit_name() == "Снайпер")
    {
        if (this->bonus() == true)
        {
//            std::cout << "Второй выстрел." << std::endl;
            return 0;
        }
    }
    if (this->get_unit_name() == "Автоматчик")
    {
        this->non_bonus();
        return -1;
    }
    if (this->get_unit_name() == "Пулеметчик")
    {
        if (this->bonus() == true)
        {
//            std::cout << "Второй ход." << std::endl;
            return 1;
        }
    }
    if (this->get_unit_name() == "Дробовик")
    {
        this->non_bonus();
        return -1;
    }

    return -1;
}
