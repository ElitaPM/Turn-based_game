#include "soldier.h"




bool MachineGunner::bonus()
{
    int chance = Bonus_chance;
    int temp = 1 + rand()%100;
    if(temp <= chance)
    {
    std::cout << "Бонус второго хода" << std::endl;
    }
    return temp > chance ? false : true;
}

bool Stormtrooper::bonus()
{
    int chance = Bonus_chance;
    int temp = 1 + rand()%100;
    return temp > chance ? false : true;
}

bool Sniper::bonus()
{
    int chance = Bonus_chance;
    int temp = 1 + rand()%100;
    if(temp <= chance)
    {
    std::cout << "Бонус второго выстрела" << std::endl;
    }
    return temp > chance ? false : true;
}

bool Shotgun::bonus()
{
    int chance = Bonus_chance;
    int temp = 1 + rand()%100;
    return temp > chance ? false : true;
}
