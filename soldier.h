#ifndef SOLDIER_H
#define SOLDIER_H
#include <utility>
#include "unit.h"
#include <string>
#include <iostream>



//class Soldier: public Unit
//{
//protected:
//    int HP;
//    int armor;
//    int Ammo;
//    int Weapon_damage;
//    int Range;
//    int Bonus_chance;
//    std::string color;
//public:
//    Soldier(std::string color) : Unit(){this->color = color;}
//    std::string get_color();
//    bool legal_shoot(std::pair<int,int> coord);
//    bool legal_move(std::pair<int,int> coord);
//    int hit_damage(int Damage);
//    //void get_damage(int Damage);
//    virtual void bonus() = 0;
//    int getAmmo(){return Ammo;}
//};

class Sniper: public Unit
{
public:
    Sniper(std::string color) : Unit(color)
    {
        HP = 100;
        armor = 0;
        Ammo = 1;
        Weapon_damage = 100;
        Range = 20;
        Bonus_chance = 10;
        Accuracy = 100;
        unit_name = "Снайпер";
    }
    void bonus() {}
    bool is_alive() { return HP > 0 ? true : false;}
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
    bool is_alive() { return HP > 0 ? true : false;}
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
        Bonus_chance = 10;
        Accuracy = 50;
        unit_name = "Пулеметчик";
    }
    void bonus() {}
    bool is_alive() { return HP > 0 ? true : false;}
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
    void bonus() {}
    bool is_alive() { return HP > 0 ? true : false;}
};

#endif // SOLDIER_H
