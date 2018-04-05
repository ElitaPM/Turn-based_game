#ifndef SOLDIER_H
#define SOLDIER_H
#include <utility>
#include "unit.h"

using namespace std;

class Soldier: public Unit
{
private:
    int Ammo;
    int Weapon_damage;
    int Range;
    int Bonus_chance;
public:
    Soldier(): Unit(){}
    void move(pair<int,int> coord);
    void shoot(pair<int,int> coord);
    bool legal_shoot(pair<int,int> coord);
    bool legal_move(pair<int,int> coord);
    int hit_damage(int Damage);
    void get_damage(int Damage);
    virtual void bonus() = 0;
    bool is_alive();
};

class Sniper: public Soldier
{
public:
    Sniper(): Soldier(){}
    void bonus();
};

class Stormtrooper: public Soldier
{
public:
    Stormtrooper(): Soldier(){}
    void bonus();
};

class MachineGunner: public Soldier
{
public:
    MachineGunner(): Soldier(){}
    void bonus();
};

class Shotgun: public Soldier
{
public:
    Shotgun(): Soldier(){}
    void bonus();
};

#endif // SOLDIER_H
