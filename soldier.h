#ifndef SOLDIER_H
#define SOLDIER_H
#include <utility>
#include "unit.h"
#include <string>

//using namespace std;

class Soldier: public Unit
{
private:
    int Ammo;
    int Weapon_damage;
    int Range;
    int Bonus_chance;
    std::string color;
public:
    Soldier(std::string color) : Unit(){this->color = color;}
    std::string get_color();
    void shoot(std::pair<int,int> coord);
    bool legal_shoot(std::pair<int,int> coord);
    bool legal_move(std::pair<int,int> coord);
    int hit_damage(int Damage);
    void get_damage(int Damage);
    virtual void bonus() = 0;
};

class Sniper: public Soldier
{
public:
    Sniper(std::string color): Soldier(color){}
    void bonus() {};
    bool is_alive()  {};
};

class Stormtrooper: public Soldier
{
public:
    Stormtrooper(std::string color): Soldier(color){}
    void bonus() {};
    bool is_alive() {};
};

class MachineGunner: public Soldier
{
public:
    MachineGunner(std::string color): Soldier(color){}
    void bonus() {};
    bool is_alive() {};
};

class Shotgun: public Soldier
{
public:
    Shotgun(std::string color): Soldier(color){}
    void bonus() {};
    bool is_alive() {};
};

#endif // SOLDIER_H
