#include <iostream>
#include "field.h"
#include "menu.h"
#include "unit.h"
#include "warbase.h"
#include <cstdlib>


using namespace std;

int main()
{
    Menu menu;
    Field field;
    Barrier barrier;
    Sniper blue_sniper_1("blue"), blue_sniper_2("blue"), blue_sniper_3("blue"), yellow_sniper_1("yellow"), yellow_sniper_2("yellow"), yellow_sniper_3("yellow");
    Stormtrooper blue_stormtrooper_1("blue"), blue_stormtrooper_2("blue"), blue_stormtrooper_3("blue"), yellow_stormtrooper_1("yellow"), yellow_stormtrooper_2("yellow"), yellow_stormtrooper_3("yellow");
    MachineGunner blue_machineGunner_1("blue"), blue_machineGunner_2("blue"), blue_machineGunner_3("blue"), yellow_machineGunner_1("yellow"), yellow_machineGunner_2("yellow"), yellow_machineGunner_3("yellow");
    Shotgun blue_shotgun_1("blue"), blue_shotgun_2("blue"), blue_shotgun_3("blue"), yellow_shotgun_1("yellow"), yellow_shotgun_2("yellow"), yellow_shotgun_3("yellow");

    Unit* blue_unit[3];
    Unit* yellow_unit[3];
    int choise;
    cout << "Голубая команда " << endl;
    menu.units_choise();
    cin >> choise;

    switch (choise) {
        case 1: blue_unit[0] = &blue_sniper_1; blue_unit[1] = &blue_sniper_2; blue_unit[2] = &blue_sniper_3; break;
        case 2: blue_unit[0] = &blue_stormtrooper_1; blue_unit[1] = &blue_stormtrooper_2; blue_unit[2] = &blue_stormtrooper_3; break;
        case 3: blue_unit[0] = &blue_machineGunner_1; blue_unit[1] = &blue_machineGunner_2; blue_unit[2] = &blue_machineGunner_3; break;
        case 4: blue_unit[0] = &blue_shotgun_1; blue_unit[1] = &blue_shotgun_2; blue_unit[2] = &blue_shotgun_3; break;
        case 5: blue_unit[0] = &blue_sniper_1; blue_unit[1] = &blue_sniper_2; blue_unit[2] = &blue_stormtrooper_1; break;
        case 6: blue_unit[0] = &blue_sniper_1; blue_unit[1] = &blue_sniper_2; blue_unit[2] = &blue_machineGunner_1; break;
        case 7: blue_unit[0] = &blue_sniper_1; blue_unit[1] = &blue_sniper_2; blue_unit[2] = &blue_shotgun_1; break;
        case 8: blue_unit[0] = &blue_stormtrooper_1; blue_unit[1] = &blue_stormtrooper_2; blue_unit[2] = &blue_sniper_1; break;
        case 9: blue_unit[0] = &blue_stormtrooper_1; blue_unit[1] = &blue_stormtrooper_2; blue_unit[2] = &blue_machineGunner_1; break;
        case 10: blue_unit[0] = &blue_stormtrooper_1; blue_unit[1] = &blue_stormtrooper_2; blue_unit[2] = &blue_shotgun_1; break;
        case 11: blue_unit[0] = &blue_machineGunner_1; blue_unit[1] = &blue_machineGunner_2; blue_unit[2] = &blue_sniper_1; break;
        case 12: blue_unit[0] = &blue_machineGunner_1; blue_unit[1] = &blue_machineGunner_2; blue_unit[2] = &blue_stormtrooper_1; break;
        case 13: blue_unit[0] = &blue_machineGunner_1; blue_unit[1] = &blue_machineGunner_2; blue_unit[2] = &blue_shotgun_1; break;
        case 14: blue_unit[0] = &blue_shotgun_1; blue_unit[1] = &blue_shotgun_2; blue_unit[2] = &blue_sniper_1; break;
        case 15: blue_unit[0] = &blue_shotgun_1; blue_unit[1] = &blue_shotgun_2; blue_unit[2] = &blue_stormtrooper_1; break;
        case 16: blue_unit[0] = &blue_shotgun_1; blue_unit[1] = &blue_shotgun_2; blue_unit[2] = &blue_machineGunner_1; break;
        case 17: blue_unit[0] = &blue_sniper_1; blue_unit[1] = &blue_stormtrooper_1; blue_unit[2] = &blue_machineGunner_1; break;
        case 18: blue_unit[0] = &blue_sniper_1; blue_unit[1] = &blue_stormtrooper_1; blue_unit[2] = &blue_shotgun_1; break;
        case 19: blue_unit[0] = &blue_sniper_1; blue_unit[1] = &blue_machineGunner_1; blue_unit[2] = &blue_shotgun_1; break;
        case 20: blue_unit[0] = &blue_stormtrooper_1; blue_unit[1] = &blue_machineGunner_1; blue_unit[2] = &blue_shotgun_1; break;
    }

    cout << "Желтая команда " << endl;
    menu.units_choise();
    cin >> choise;

    switch (choise) {
        case 1: yellow_unit[0] = &yellow_sniper_1; yellow_unit[1] = &yellow_sniper_2; yellow_unit[2] = &yellow_sniper_3; break;
        case 2: yellow_unit[0] = &yellow_stormtrooper_1; yellow_unit[1] = &yellow_stormtrooper_2; yellow_unit[2] = &yellow_stormtrooper_3; break;
        case 3: yellow_unit[0] = &yellow_machineGunner_1; yellow_unit[1] = &yellow_machineGunner_2; yellow_unit[2] = &yellow_machineGunner_3; break;
        case 4: yellow_unit[0] = &yellow_shotgun_1; yellow_unit[1] = &yellow_shotgun_2; yellow_unit[2] = &yellow_shotgun_3; break;
        case 5: yellow_unit[0] = &yellow_sniper_1; yellow_unit[1] = &yellow_sniper_2; yellow_unit[2] = &yellow_stormtrooper_1; break;
        case 6: yellow_unit[0] = &yellow_sniper_1; yellow_unit[1] = &yellow_sniper_2; yellow_unit[2] = &yellow_machineGunner_1; break;
        case 7: yellow_unit[0] = &yellow_sniper_1; yellow_unit[1] = &yellow_sniper_2; yellow_unit[2] = &yellow_shotgun_1; break;
        case 8: yellow_unit[0] = &yellow_stormtrooper_1; yellow_unit[1] = &yellow_stormtrooper_2; yellow_unit[2] = &yellow_sniper_1; break;
        case 9: yellow_unit[0] = &yellow_stormtrooper_1; yellow_unit[1] = &yellow_stormtrooper_2; yellow_unit[2] = &yellow_machineGunner_1; break;
        case 10: yellow_unit[0] = &yellow_stormtrooper_1; yellow_unit[1] = &yellow_stormtrooper_2; yellow_unit[2] = &yellow_shotgun_1; break;
        case 11: yellow_unit[0] = &yellow_machineGunner_1; yellow_unit[1] = &yellow_machineGunner_2; yellow_unit[2] = &yellow_sniper_1; break;
        case 12: yellow_unit[0] = &yellow_machineGunner_1; yellow_unit[1] = &yellow_machineGunner_2; yellow_unit[2] = &yellow_stormtrooper_1; break;
        case 13: yellow_unit[0] = &yellow_machineGunner_1; yellow_unit[1] = &yellow_machineGunner_2; yellow_unit[2] = &yellow_shotgun_1; break;
        case 14: yellow_unit[0] = &yellow_shotgun_1; yellow_unit[1] = &yellow_shotgun_2; yellow_unit[2] = &yellow_sniper_1; break;
        case 15: yellow_unit[0] = &yellow_shotgun_1; yellow_unit[1] = &yellow_shotgun_2; yellow_unit[2] = &yellow_stormtrooper_1; break;
        case 16: yellow_unit[0] = &yellow_shotgun_1; yellow_unit[1] = &yellow_shotgun_2; yellow_unit[2] = &yellow_machineGunner_1; break;
        case 17: yellow_unit[0] = &yellow_sniper_1; yellow_unit[1] = &yellow_stormtrooper_1; yellow_unit[2] = &yellow_machineGunner_1; break;
        case 18: yellow_unit[0] = &yellow_sniper_1; yellow_unit[1] = &yellow_stormtrooper_1; yellow_unit[2] = &yellow_shotgun_1; break;
        case 19: yellow_unit[0] = &yellow_sniper_1; yellow_unit[1] = &yellow_machineGunner_1; yellow_unit[2] = &yellow_shotgun_1; break;
        case 20: yellow_unit[0] = &yellow_stormtrooper_1; yellow_unit[1] = &yellow_machineGunner_1; yellow_unit[2] = &yellow_shotgun_1; break;
    }


    WarBase wb1,wb2;

    field.init(blue_unit[0], blue_unit[1], blue_unit[2], yellow_unit[0], yellow_unit[1], yellow_unit[2], wb1, wb2, barrier);
    menu.print(field);
    menu.print();

//    while(1)
//    {
//        cout << blue_unit[0]->get_coord().first + 1 << " " << blue_unit[0]->get_coord().second + 1 << endl;
//    field.move(blue_unit[0]);
//    menu.print(field);
//    menu.print();
//        cout << yellow_unit[0]->get_coord().first + 1 << " " << yellow_unit[0]->get_coord().second + 1 << endl;
//    field.move(yellow_unit[0]);
//    menu.print(field);
//    menu.print();
//    }

    return 0;

}
