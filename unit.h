#ifndef UNIT_H
#define UNIT_H
#include <utility>
#include <string>



class Unit
{
protected:
    int HP;
    int armor;
    int Ammo;
    int Weapon_damage;
    int Range;
    int Bonus_chance;
    std::string color;
    std::pair <int, int> coord;
public:
    Unit(std::string color){this->color = color;}
    std::string get_color();
    bool legal_shoot(std::pair<int,int> coord);
    bool legal_move(std::pair<int,int> coord);
    int hit_damage(int Damage);
    void get_damage(int Damage);
    virtual void bonus() = 0;


    int getAmmo(){return Ammo;}


    virtual bool is_alive() = 0;
    void set_coord(int first, int second);
    std::pair<int, int> get_coord();
};

#endif // UNIT_H
