#ifndef UNIT_H
#define UNIT_H
#include <utility>
#include <string>
#include <iostream>



class Unit
{
protected:
    int HP;
    int armor;
    int Ammo;
    int Weapon_damage;
    int Range;
    int Bonus_chance;
    int Accuracy;
    std::string color;
    std::pair <int, int> coord;
    std::string unit_name;
public:
    Unit(std::string color){this->color = color;}
    std::string get_color(){return color;}
    std::string get_unit_name();
    bool legal_shoot(std::pair<int,int> coord);
    bool legal_move(std::pair<int,int> coord);
    int hit_damage(int Damage);
    void showHP ();
    void get_damage(int Damage)
    {
        HP = HP - (Damage-Damage*armor/10);
    }
    virtual void bonus() = 0;


    int getAmmo(){return Ammo;}
    int getRange() {return Range;}
    int getAccuracy() {return Accuracy;}
    int getWeapon_damage(){return Weapon_damage;}

    bool is_alive() { return HP > 0 ? true : false;}
    void set_coord(int first, int second);
    std::pair<int, int> get_coord();
};

#endif // UNIT_H
