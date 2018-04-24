#ifndef SOLDIER_H
#define SOLDIER_H
#include <utility>
#include "unit.h"
#include <string>
#include <iostream>



class Soldier: public Unit
{
protected:
    int HP;
    int armor;
    int Ammo;
    int Weapon_damage;
    int Range;
    int Bonus_chance;
    std::string color;
public:
    Soldier(std::string color) : Unit(){this->color = color;}
    std::string get_color();
    bool legal_shoot(std::pair<int,int> coord);
    bool legal_move(std::pair<int,int> coord);
    int hit_damage(int Damage);
    //void get_damage(int Damage);
    virtual void bonus() = 0;
};

class Sniper: public Soldier
{
public:
    Sniper(std::string color) : Soldier(color)
    {
        HP = 100;
        armor = 0;
        Ammo = 1;
        Weapon_damage = 100;
        Range = 12;
        Bonus_chance = 10;
    }
    void bonus() {}
    void get_damage(int Damage);
    void showHP () { std::cout << HP << std::endl;}
    bool is_alive() { return HP > 0 ? true : false;}
};

class Stormtrooper: public Soldier
{
public:
    Stormtrooper(std::string color) : Soldier(color)
    {
        HP = 150;
        armor = 3;
        Ammo = 10;
        Weapon_damage = 20;
        Range = 10;
        Bonus_chance = 10;
    }
    void bonus() {}
    bool is_alive() {}
};

class MachineGunner: public Soldier
{
public:
    MachineGunner(std::string color) : Soldier(color)
    {
        HP = 300;
        armor = 3;
        Ammo = 35;
        Weapon_damage = 7;
        Range = 6;
        Bonus_chance = 10;
    }
    void bonus() {}
    bool is_alive() {}
};

class Shotgun: public Soldier
{
public:
    Shotgun(std::string color) : Soldier(color)
    {
        HP = 300;
        armor = 5;
        Ammo = 3;
        Weapon_damage = 200;
        Range = 7;
        Bonus_chance = 10;
    }
    void bonus() {}
    bool is_alive() {}
};

#endif // SOLDIER_H
