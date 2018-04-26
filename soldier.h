#ifndef SOLDIER_H
#define SOLDIER_H
#include <utility>
#include "unit.h"
#include <string>
#include <iostream>



class Sniper: public Unit
{
public:
    Sniper(std::string color) : Unit(color)
    {
        HP = 100;
        armor = 0;
        Ammo = 1;
        Weapon_damage = 100;
        Range = 12;
        Bonus_chance = 10;
        Accuracy = 100;
        unit_name = "Снайпер";
    }
    void bonus() {}
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
        Range = 10;
        Bonus_chance = 10;
        Accuracy = 80;
        unit_name = "Автоматчик";
    }
    void bonus() {}
};

class MachineGunner: public Unit
{
public:
    MachineGunner(std::string color) : Unit(color)
    {
        HP = 300;
        armor = 3;
        Ammo = 50;
        Weapon_damage = 10;
        Range = 8;
        Bonus_chance = 10;
        Accuracy = 60;
        unit_name = "Пулеметчик";
    }
    void bonus() {}
};

class Shotgun: public Unit
{
public:
    Shotgun(std::string color) : Unit(color)
    {
        HP = 200;
        armor = 5;
        Ammo = 3;
        Weapon_damage = 200;
        Range = 8;
        Bonus_chance = 10;
        Accuracy = 100;
        unit_name = "Дробовик";
    }
    void bonus() {}
};

#endif // SOLDIER_H
