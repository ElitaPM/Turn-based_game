#include "unit.h"

Unit::Unit(std::string color)
{
    this->color = color;
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

void Unit::set_armor(int armor)
{
    this->armor = armor;
}


void Unit::get_damage(int Damage, bool desolator)
{
    HP = HP - (Damage-((int)desolator)*Damage*armor/10);
}
int Unit::getAmmo()
{
    return Ammo;
}
int Unit::getRange()
{
    return Range;
}
int Unit::getAccuracy()
{
    return Accuracy;
}
int Unit::getArmor()
{
    return armor;
}
int Unit::getWeapon_damage()
{
    return Weapon_damage;
}

bool Unit::is_alive()
{
    return HP > 0 ? true : false;
}

std::string Unit::get_color()
{
    return color;
}




int Unit::choise(int menu_count, bool exit)
{
    std::string buffer;
    int number;
    if(exit)

        {
            do
                {

                    std::getline(std::cin, buffer);
                    number = std::atoi(buffer.c_str());
                    if(buffer.find(' ') == -1 || buffer.find('\t') == -1)
                    {
                                for(unsigned int i = 0; i < buffer.size(); i++)
                                    {
                                        if(!(std::isdigit(buffer[i],std::locale())))
                                            {
                                                number = -1;
                                                break;
                                            }
                                    }
                    }
                }
            while(number > menu_count || number < 1);

            return number;
        }



    else
        {
                std::cin.ignore();

            do
                {

                    std::getline(std::cin, buffer);
                    number = std::atoi(buffer.c_str());
                    if(buffer.find(' ') == -1 || buffer.find('\t') == -1)
                    {
                        if(number == 0)
                            {
                                for(unsigned int i = 0; i < buffer.size(); i++)
                                    {
                                        if(!(std::isdigit(buffer[i],std::locale())))
                                            {
                                                number = -1;
                                                break;
                                            }
                                    }
                            }
                    }
                }
            while(number > menu_count || number < 0);

            return number;
        }
}
