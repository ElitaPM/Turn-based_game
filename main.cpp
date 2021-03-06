#include <iostream>
#include "field.h"
#include "menu.h"
#include "unit.h"
#include "warbase.h"
#include <cstdlib>


using namespace std;

int main()
{
    int ch;

    while (1)
    {
        cout << "1. Начать игру." << endl;
        cout << "2. Правила игры." << endl;
        cout << "3. Характеристики юнитов." << endl;
        cout << "0. Выход." << endl;

        ch = Unit::choise(3,0);

        cout << "\x1B[2J\x1B[H";


        switch (ch)
        {
           case 1:
           {
                cout << "\x1B[2J\x1B[H";

    Menu menu;
    Field field;
    Barrier barrier("");
    Sniper blue_sniper_1("blue"), blue_sniper_2("blue"), blue_sniper_3("blue"), yellow_sniper_1("yellow"), yellow_sniper_2("yellow"), yellow_sniper_3("yellow");
    Stormtrooper blue_stormtrooper_1("blue"), blue_stormtrooper_2("blue"), blue_stormtrooper_3("blue"), yellow_stormtrooper_1("yellow"), yellow_stormtrooper_2("yellow"), yellow_stormtrooper_3("yellow");
    MachineGunner blue_machineGunner_1("blue"), blue_machineGunner_2("blue"), blue_machineGunner_3("blue"), yellow_machineGunner_1("yellow"), yellow_machineGunner_2("yellow"), yellow_machineGunner_3("yellow");
    Shotgun blue_shotgun_1("blue"), blue_shotgun_2("blue"), blue_shotgun_3("blue"), yellow_shotgun_1("yellow"), yellow_shotgun_2("yellow"), yellow_shotgun_3("yellow");

    Unit* blue_unit[3];
    Unit* yellow_unit[3];
    int choise;
    cout << "Blue team " << endl;
    menu.units_choise();
    choise = Unit::choise(20);

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

    cout << "Yellow team " << endl;
    menu.units_choise();
    choise = Unit::choise(20);

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


    WarBase wb1("blue"),wb2("yellow");
    Unit* blue_base = &wb1;
    Unit* yellow_base = &wb2;

    field.init(blue_unit[0], blue_unit[1], blue_unit[2], yellow_unit[0], yellow_unit[1], yellow_unit[2], wb1, wb2, barrier);
    menu.print(field);
    menu.print(blue_unit,yellow_unit, blue_base, yellow_base);

    bool blue_team_immortal = true;
    bool yellow_team_immortal = true;

    while(1)
    {
        if(blue_unit[0]->is_alive())
        {
    cout << "Ход юнита Blue team " << blue_unit[0]->get_unit_name() << " с координатами: " << "(" <<
    blue_unit[0]->get_coord().first + 1 << "," << blue_unit[0]->get_coord().second + 1 << ")"<< endl;
    field.move(blue_unit[0]);
        }
        if(blue_unit[1]->is_alive())
        {
    cout << "Ход юнита Blue team " << blue_unit[1]->get_unit_name() << " с координатами: " << "(" <<
    blue_unit[1]->get_coord().first + 1 << "," << blue_unit[1]->get_coord().second + 1 << ")"<< endl;
    field.move(blue_unit[1]);
        }
        if(blue_unit[2]->is_alive())
        {
    cout << "Ход юнита Blue team " << blue_unit[2]->get_unit_name() << " с координатами: " << "(" <<
    blue_unit[2]->get_coord().first + 1 << "," << blue_unit[2]->get_coord().second + 1 << ")"<< endl;
    field.move(blue_unit[2]);
        }
    int blue_unit_1_armor = blue_unit[0]->getArmor();
    int blue_unit_2_armor = blue_unit[1]->getArmor();
    int blue_unit_3_armor = blue_unit[2]->getArmor();
    int blue_base_armor = blue_base->getArmor();
        if(blue_team_immortal)
        {
            cout << "Использовать неуязвимость?" << endl;
            cout << "1. Да" << endl;
            cout << "2. Нет" << endl;
            choise = Unit::choise(2);
            switch (choise) {
            case 1: wb1.ability(blue_unit, blue_base); blue_team_immortal = false; break;
            case 2: break;
            }
        }
        menu.print(blue_unit,yellow_unit, blue_base, yellow_base);
        if(yellow_unit[0]->is_alive())
        {
    cout << "Выстрел юнита Yellow team " << yellow_unit[0]->get_unit_name() << " с координатами: " << "(" <<
    yellow_unit[0]->get_coord().first + 1 << "," << yellow_unit[0]->get_coord().second + 1 << ")"<< endl;
    field.shoot(yellow_unit[0]);
        }
        if(yellow_unit[1]->is_alive())
        {
    cout << "Выстрел юнита Yellow team " << yellow_unit[1]->get_unit_name() << " с координатами: " << "(" <<
    yellow_unit[1]->get_coord().first + 1 << "," << yellow_unit[1]->get_coord().second + 1 << ")"<< endl;
    field.shoot(yellow_unit[1]);
        }
        if(yellow_unit[2]->is_alive())
        {
    cout << "Выстрел юнита Yellow team " << yellow_unit[2]->get_unit_name() << " с координатами: " << "(" <<
    yellow_unit[2]->get_coord().first + 1 << "," << yellow_unit[2]->get_coord().second + 1 << ")"<< endl;
    field.shoot(yellow_unit[2]);
        }
        if(!blue_team_immortal)
        {
            blue_unit[0]->set_armor(blue_unit_1_armor);
            blue_unit[1]->set_armor(blue_unit_2_armor);
            blue_unit[2]->set_armor(blue_unit_3_armor);
        }

    menu.print(field);
    menu.print(blue_unit,yellow_unit, blue_base, yellow_base);


    if(!blue_unit[0]->is_alive() && !blue_unit[1]->is_alive() && !blue_unit[2]->is_alive() || !blue_base->is_alive())
    {
        cout << "Победила команда Yellow!" << endl;
        break;
    }

        if(yellow_unit[0]->is_alive())
        {
    cout << "Ход юнита Yellow team " << yellow_unit[0]->get_unit_name() << " с координатами: " << "(" <<
    yellow_unit[0]->get_coord().first + 1 << "," << yellow_unit[0]->get_coord().second + 1 << ")"<< endl;
    field.move(yellow_unit[0]);
        }
        if(yellow_unit[1]->is_alive())
        {
    cout << "Ход юнита Yellow team " << yellow_unit[1]->get_unit_name() << " с координатами: " << "(" <<
    yellow_unit[1]->get_coord().first + 1 << "," << yellow_unit[1]->get_coord().second + 1 << ")"<< endl;
    field.move(yellow_unit[1]);
        }
        if(yellow_unit[2]->is_alive())
        {
    cout << "Ход юнита Yellow team " << yellow_unit[2]->get_unit_name() << " с координатами: " << "(" <<
    yellow_unit[2]->get_coord().first + 1 << "," << yellow_unit[2]->get_coord().second + 1 << ")"<< endl;
    field.move(yellow_unit[2]);
        }
        int yellow_unit_1_armor = yellow_unit[0]->getArmor();
        int yellow_unit_2_armor = yellow_unit[1]->getArmor();
        int yellow_unit_3_armor = yellow_unit[2]->getArmor();
        int yellow_base_armor = yellow_base->getArmor();
            if(yellow_team_immortal)
            {
                cout << "Использовать неуязвимость?" << endl;
                cout << "1. Да" << endl;
                cout << "2. Нет" << endl;
                choise = Unit::choise(2);
                switch (choise) {
                case 1: wb2.ability(yellow_unit, yellow_base); yellow_team_immortal = false; break;
                case 2: break;
                }
            }
    menu.print(blue_unit,yellow_unit, blue_base, yellow_base);
        if(blue_unit[0]->is_alive())
        {
    cout << "Выстрел юнита Blue team " << blue_unit[0]->get_unit_name() << " с координатами: " << "(" <<
    blue_unit[0]->get_coord().first + 1 << "," << blue_unit[0]->get_coord().second + 1 << ")"<< endl;
    field.shoot(blue_unit[0]);
        }
        if(blue_unit[1]->is_alive())
        {
    cout << "Выстрел юнита Blue team " << blue_unit[1]->get_unit_name() << " с координатами: " << "(" <<
    blue_unit[1]->get_coord().first + 1 << "," << blue_unit[1]->get_coord().second + 1 << ")"<< endl;
    field.shoot(blue_unit[1]);
        }
        if(blue_unit[2]->is_alive())
        {
    cout << "Выстрел юнита Blue team " << blue_unit[2]->get_unit_name() << " с координатами: " << "(" <<
    blue_unit[2]->get_coord().first + 1 << "," << blue_unit[2]->get_coord().second + 1 << ")"<< endl;
    field.shoot(blue_unit[2]);
        }

        if(!yellow_team_immortal)
        {
            yellow_unit[0]->set_armor(yellow_unit_1_armor);
            yellow_unit[1]->set_armor(yellow_unit_2_armor);
            yellow_unit[2]->set_armor(yellow_unit_3_armor);
        }

    menu.print(field);
    menu.print(blue_unit,yellow_unit, blue_base, yellow_base);

    if(!yellow_unit[0]->is_alive() && !yellow_unit[1]->is_alive() && !yellow_unit[2]->is_alive() || !yellow_base->is_alive())
    {
        cout << "Победила команда Blue!" << endl;
        break;
    }

    }

    break;
                }
                case 2:
                {
                    cout << "\x1B[2J\x1B[H";
                    cout << "Правила игры." << endl;
                    cout << "Графическая составляющая игры состоит из поля размером 20x20 клеток. Каждая клетка определяет единицу расстояния. В клетках располагаются игровые юниты: солдаты, военная база, препятствия." << endl;
                    cout << "Игра является пошаговой стратегией и расчитана на двух игроков. Игроки делятся на Blue team(слева) и Yellow team(справа). Каждая команда состоит из военной базы(главного стратегического объекта), 3 управляемых юнита-солдата с различным видом оружия. Основная цель игры - уничтожить вражескую военную базу или оставить вражескую команду без армии." << endl;
                    cout << "В момент старта игры игроки выбирают вид оружия для каждого из своих солдат. Военная база случайным образом располагается на первом(Blue team) и последнем(Yellow team) столбце. Солдаты каждой из команд соответственно в первых 3 или последних трех столбцах. Также случайным образом располагаются препятствия по карте." << endl;
                    cout << "За один ход игрок ходит и стреляет всеми своими солдатами. Ходить и стрелять можно в любую сторону. Расстояние шага одна клетка, выстрела в зависимости от вида оружия. Шаг через препятствие невозможен. Выстрел возможен, но не имеет смысла." << endl;
                    cout << "Каждый управляемый юнит(включая военную базу) имеет некоторое количество жизней, когда это число становится меньшим либо равным нулю, юнит погибает и исчезает с поля. Уменьшаться число жизней может от выстрела противника на число, определяемое уроном оружия, количеством попавших патронов, броней персонажа." << endl;
                    cout << "Военная база является главным стратегическим объектом, однако очень ограничена в использовании. Она не может передвигаться по полю и имеет лишь одну способность - на 1 ход сделать себя и все свои подконтрольные юниты неуязвимыми." << endl;
                    cout << "Солдаты делятся по типу оружия на: снайпер, пулеметчик, автоматчик, дробовик." << endl;
                    cout << "Каждый вид оружия имеет различную дальность выстрела, количество патронов, урон с патрона, а также свою уникальную способность. Например у солдата с пулеметом есть шанс сделать бонусный шаг за 1 ход." << endl;
                    cout << "Выстрел осуществляется указанием координаты цели(клетки поля подписаны соответствующими координатами). На вероятность попадания влияет как точность оружия, так и расстояние между врагами. " << endl;
                    cout << "Траектория пули при нелинейном выстреле расчитывается с использованием математических законов и псевдорандома. То есть существует возможность выстрелить более чем в одного юнита." << endl;

                    break;
                }

                case 3:
                            {
                                cout << "\x1B[2J\x1B[H";
                                cout << "Снайпер:" << endl;
                                cout << "Дальность атаки: 14" << endl;
                                cout << "Урон с патрона: 100" << endl;
                                cout << "Количество патронов : 1" << endl;
                                cout << "Броня : 0%" << endl;
                                cout << "Точность : 100%" << endl;
                                cout << "Колчиество HP : 100" << endl;
                                cout << "Уникальная способность: второй выстрел" << endl;
                                cout << endl;
                                cout << endl;

                                cout << "Автоматчик:" << endl;
                                cout << "Дальность атаки: 12" << endl;
                                cout << "Урон с патрона: 20" << endl;
                                cout << "Количество патронов : 10" << endl;
                                cout << "Броня : 30%" << endl;
                                cout << "Точность : 80%" << endl;
                                cout << "Колчиество HP : 150" << endl;
                                cout << "Уникальная способность: критический урон(х2) " << endl;
                                cout << endl;
                                cout << endl;

                                cout << "Пулеметчик:" << endl;
                                cout << "Дальность атаки: 8" << endl;
                                cout << "Урон с патрона: 12" << endl;
                                cout << "Количество патронов : 50" << endl;
                                cout << "Броня : 30%" << endl;
                                cout << "Точность : 30%" << endl;
                                cout << "Колчиество HP : 300" << endl;
                                cout << "Уникальная способность: второй шаг" << endl;
                                cout << endl;
                                cout << endl;

                                cout << "Дробовик:" << endl;
                                cout << "Дальность атаки: 8" << endl;
                                cout << "Урон с патрона: 200" << endl;
                                cout << "Количество патронов : 3" << endl;
                                cout << "Броня : 50%" << endl;
                                cout << "Точность : 30%" << endl;
                                cout << "Колчиество HP : 200" << endl;
                                cout << "Уникальная способность: нанесение урона без учета брони" << endl;
                                cout << endl;
                                cout << endl;

                                cout << "База:" << endl;
                                cout << "Броня : 50%" << endl;
                                cout << "Колчиество HP : 500" << endl;
                                cout << "Уникальная способность: неуязвимость для всей команды (1 раз за игру)" << endl;
                                cout << endl;
                                cout << endl;

                                break;
                            }
                case 0:
                {
                    cout << "\x1B[2J\x1B[H";
                    exit(0);
                }

            }
        }

    return 0;

}
