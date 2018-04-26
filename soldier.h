#ifndef SOLDIER_H
#define SOLDIER_H
#include <utility>
#include "unit.h"
#include <string>
#include <iostream>
#include <time.h>

class Sniper: public Unit
{
public:
    Sniper(std::string color) : Unit(color)
    {
        HP = 100;
        armor = 0;
        Ammo = 1;
        Weapon_damage = 100;
        Range = 15;
        Bonus_chance = 100;
        Accuracy = 100;
        unit_name = "Снайпер";
    }
    bool bonus(); //{}
};

class Stormtrooper: public Unit
{
public:
    Stormtrooper(std::string color) : Unit(color)
    {
        HP = 150;
        armor = 3;
        Ammo = 10;
        Weapon_damage = 20;
        Range = 15;
        Bonus_chance = 100;
        Accuracy = 80;
        unit_name = "Автоматчик";
    }
    bool bonus(); // {}
//    void non_bonus;
};

class MachineGunner: public Unit
{
public:
    MachineGunner(std::string color) : Unit(color)
    {
        HP = 300;
        armor = 3;
        Ammo = 35;
        Weapon_damage = 7;
        Range = 6;
        Bonus_chance = 100;
        Accuracy = 50;
        unit_name = "Пулеметчик";
    }
    bool bonus(); // {}
};

class Shotgun: public Unit
{
public:
    Shotgun(std::string color) : Unit(color)
    {
        HP = 300;
        armor = 5;
        Ammo = 3;
        Weapon_damage = 200;
        Range = 7;
        Bonus_chance = 10;
        Accuracy = 100;
        unit_name = "Дробовик";
    }
    bool bonus() {}
};

#endif // SOLDIER_H
