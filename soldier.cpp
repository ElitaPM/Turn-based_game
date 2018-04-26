#include "soldier.h"

/*
Soldier::Soldier(string color): Unit::Unit()
{
    this->color = color;
}
*/






//Stormtrooper::Stormtrooper()
//{

//}

//MachineGunner::MachineGunner()
//{

//}

//Shotgun::Shotgun()
//{

//}

//*/


bool Sniper::bonus()
{
    srand(NULL);
    int lucky = rand()%100;
    if (100 - lucky >= 100 - Bonus_chance)
    {
        std::cout << "Второй выстрел." << std::endl;
        return true;
    }
    else return false;
}

bool Stormtrooper::bonus()
{
    srand(NULL);
    int lucky = rand()%100;
    if (100 - lucky >= 100 - Bonus_chance)
    {
        Weapon_damage = 50;
        std::cout << "Критический урон." << std::endl;
        return true;
    }
    else return false;
}

bool MachineGunner::bonus()
{
    srand(NULL);
    int lucky = rand()%100;
    if (100 - lucky >= 100 - Bonus_chance)
    {
        std::cout << "Второй ход." << std::endl;
        return true;
    }
    else return false;
}
