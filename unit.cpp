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

void Unit::before(Unit* soldier)
{
    if (soldier->get_unit_name() == "Автоматчик")
    {
        soldier->bonus();
//            std::cout << "Критический урон." << std::endl;
    }
    if (soldier->get_unit_name() == "Дробовик")
    {
        soldier->bonus();
    }
}

void Unit::non_bonus(Unit* soldier)
{
    if (soldier->get_unit_name() == "Автоматчик")
    {
        Weapon_damage = 20;
    }
    if (soldier->get_unit_name() == "Дробовик")
    {
        Weapon_damage = 200;
    }
}

int Unit::after(Unit *soldier)
{
    if (soldier->get_unit_name() == "Снайпер")
    {
        if (soldier->bonus() == true)
        {
//            std::cout << "Второй выстрел." << std::endl;
            return 0;
        }
    }
    if (soldier->get_unit_name() == "Автоматчик")
    {
        soldier->non_bonus(soldier);
        return -1;
    }
    if (soldier->get_unit_name() == "Пулеметчик")
    {
        if (soldier->bonus() == true)
        {
//            std::cout << "Второй ход." << std::endl;
            return 1;
        }
    }
    if (soldier->get_unit_name() == "Дробовик")
    {
        soldier->non_bonus(soldier);
        return -1;
    }

    return -1;
}
