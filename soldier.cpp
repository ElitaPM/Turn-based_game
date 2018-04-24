#include "soldier.h"

/*
Soldier::Soldier(string color): Unit::Unit()
{
    this->color = color;
}
*/
std::string Soldier::get_color()
{
    return this->color;
}

void Sniper::get_damage(int Damage)
{
    HP -= Damage;
}



//Stormtrooper::Stormtrooper()
//{

//}

//MachineGunner::MachineGunner()
//{

//}

//Shotgun::Shotgun()
//{

//}

//*/


