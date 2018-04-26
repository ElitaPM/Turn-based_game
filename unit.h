#ifndef UNIT_H
#define UNIT_H
#include <utility>
#include <string>
#include <iostream>
#include <locale>



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
    Unit(std::string color);
    std::string get_color();
    std::string get_unit_name();

    void showHP ();
    void get_damage(int Damage, bool desolator = true);

    virtual bool bonus() = 0;


    int getAmmo();
    int getRange();
    int getAccuracy();
    int getArmor();
    int getWeapon_damage();

    bool is_alive();
    void set_coord(int first, int second);
    void set_armor(int armor);
    std::pair<int, int> get_coord();

    static int choise(int menu_count, bool exit = true);

};

#endif // UNIT_H
