#include "field.h"
#include "unit.h"
#include "warbase.h"
#include "barrier.h"
#include <typeinfo>
#include "soldier.h"
#include <cstdlib>
#include <ctime>

Field::Field()
{

}

void Field::units_simbol(char** symbols)
{
    Barrier barrier("");
    WarBase base("");
    Sniper sniper("");
    Stormtrooper stormtr("");
    MachineGunner machinegun("");
    Shotgun gun("");
    for (int j=0; j<20; j++)
    {
        for (int i=0; i<20; i++)
        {
            if (ptr[j][i] != NULL)
            {
                if (typeid(*ptr[j][i]) == typeid(sniper))
                {
                    if(ptr[j][i]->get_color() == "blue")
                            symbols[j][i] = 'S';
                    else
                            symbols[j][i] = 's';
                }
                else if (typeid(*ptr[j][i]) == typeid(stormtr))
                {
                    if(ptr[j][i]->get_color() == "blue")
                            symbols[j][i] = 'A';
                    else
                            symbols[j][i] = 'a';
                }
                else if (typeid(*ptr[j][i]) == typeid(machinegun))
                {
                    if(ptr[j][i]->get_color() == "blue")
                            symbols[j][i] = 'P';
                    else
                            symbols[j][i] = 'p';
                }
                else if (typeid(*ptr[j][i]) == typeid(gun))
                {
                    if(ptr[j][i]->get_color() == "blue")
                            symbols[j][i] = 'G';
                    else
                            symbols[j][i] = 'g';
                }
                else if (typeid(*ptr[j][i]) == typeid(base))
                {
                    if(ptr[j][i]->get_color() == "blue")
                            symbols[j][i] = 'B';
                    else
                            symbols[j][i] = 'b';
                }
                else if (typeid(*ptr[j][i]) == typeid(barrier))
                {
                    symbols[j][i] ='O';
                }
            }
            else
            {
                symbols[j][i] =' ';
            }
        }
    }
}

void Field::init(Unit* blueUnit_1,
                 Unit* blueUnit_2,
                 Unit* blueUnit_3,
                 Unit* yellowUnit_1,
                 Unit* yellowUnit_2,
                 Unit* yellowUnit_3,
                 WarBase& blueWarBase,
                 WarBase& yellowWarBase, Barrier &barrier)
{

    srand(time(NULL));

    int blueWarBaseLocation = rand()%20;
    blueWarBase.set_coord(blueWarBaseLocation , 0);
    int yellowWarBaseLocation = rand()%20;
    yellowWarBase.set_coord(yellowWarBaseLocation , 19);
    std::pair<int , int> blueUnit_1Coord, blueUnit_2Coord, blueUnit_3Coord, yellowUnit_1Coord, yellowUnit_2Coord, yellowUnit_3Coord;


    blueUnit_1Coord.second = rand()%3;
    if (blueUnit_1Coord.second == 0)
    {
        do
        {
           blueUnit_1Coord.first = rand()%20;
        } while(blueUnit_1Coord.first == blueWarBaseLocation);
    }

    blueUnit_2Coord.second = rand()%3;
    if (blueUnit_2Coord.second == 0)
    {
        do
        {
           blueUnit_2Coord.first = rand()%20;
        } while(blueUnit_2Coord.first == blueWarBaseLocation || blueUnit_2Coord.first == blueUnit_1Coord.first);
    }
    else
    {
        do
        {
            blueUnit_2Coord.first = rand()%20;
        } while (blueUnit_1Coord == blueUnit_2Coord);
    }

    blueUnit_3Coord.second = rand()%3;
    if (blueUnit_3Coord.second == 0)
    {
        do
        {
           blueUnit_3Coord.first = rand()%20;
        } while(blueUnit_3Coord.first == blueWarBaseLocation ||
                blueUnit_3Coord.first == blueUnit_1Coord.first ||
                blueUnit_3Coord.first == blueUnit_2Coord.first);
    }
    else
    {
        do
        {
            blueUnit_3Coord.first = rand()%20;
        } while (blueUnit_3Coord == blueUnit_1Coord || blueUnit_3Coord == blueUnit_2Coord);
    }

    ///////////////////////////////////////////////////////////////////////////////

    yellowUnit_1Coord.second = 17 + rand()%3;
    if (yellowUnit_1Coord.second == 19)
    {
        do
        {
           yellowUnit_1Coord.first = rand()%20;
        } while(yellowUnit_1Coord.first == yellowWarBaseLocation);
    }

    yellowUnit_2Coord.second = 17 + rand()%3;
    if (yellowUnit_2Coord.second == 19)
    {
        do
        {
           yellowUnit_2Coord.first = rand()%20;
        } while(yellowUnit_2Coord.first == yellowWarBaseLocation || yellowUnit_2Coord.first == yellowUnit_1Coord.first);
    }
    else
    {
        do
        {
            yellowUnit_2Coord.first = rand()%20;
        } while (yellowUnit_1Coord == yellowUnit_2Coord);
    }

    yellowUnit_3Coord.second = 17 + rand()%3;
    if (yellowUnit_3Coord.second == 19)
    {
        do
        {
           yellowUnit_3Coord.first = rand()%20;
        } while(yellowUnit_3Coord.first == yellowWarBaseLocation ||
                yellowUnit_3Coord.first == yellowUnit_1Coord.first ||
                yellowUnit_3Coord.first == yellowUnit_2Coord.first);
    }
    else
    {
        do
        {
            yellowUnit_3Coord.first = rand()%20;
        } while (yellowUnit_3Coord == yellowUnit_1Coord || yellowUnit_3Coord == yellowUnit_2Coord);
    }

    ////////////////////////////////////////////////////////////////////////////////////

    std::pair <int,int> barrier_1_size_3_coord,
                   barrier_1_size_2_coord,
                   barrier_2_size_2_coord,
                   barrier_1_size_1_coord,
                   barrier_2_size_1_coord,
                   barrier_3_size_1_coord;

    barrier_1_size_3_coord.second = rand()%14 + 3;
    barrier_1_size_3_coord.first = rand()%18 + 1;

    barrier_1_size_2_coord.second = rand()%14 + 3;
    if (barrier_1_size_2_coord.second == barrier_1_size_3_coord.second)
    {
        do
        {
            barrier_1_size_2_coord.first = rand()%19 + 1;
        } while (barrier_1_size_2_coord.first == barrier_1_size_3_coord.first ||
                 barrier_1_size_2_coord.first == barrier_1_size_3_coord.first + 1 ||
                 barrier_1_size_2_coord.first == barrier_1_size_3_coord.first - 1 ||
                 barrier_1_size_2_coord.first == barrier_1_size_3_coord.first + 2);
    }
    else
    {
        barrier_1_size_2_coord.first = rand()%19 + 1;
    }

    barrier_2_size_2_coord.second = rand()%14 + 3;
    if (barrier_2_size_2_coord.second == barrier_1_size_3_coord.second ||
        barrier_2_size_2_coord.second == barrier_1_size_2_coord.second)
    {
        do
        {
            barrier_2_size_2_coord.first = rand()%19 + 1;
        } while (barrier_2_size_2_coord.first == barrier_1_size_3_coord.first ||
                 barrier_2_size_2_coord.first == barrier_1_size_3_coord.first + 1 ||
                 barrier_2_size_2_coord.first == barrier_1_size_3_coord.first - 1 ||
                 barrier_2_size_2_coord.first == barrier_1_size_3_coord.first + 2 ||
                 barrier_2_size_2_coord.first == barrier_1_size_2_coord.first ||
                 barrier_2_size_2_coord.first == barrier_1_size_2_coord.first + 1 ||
                 barrier_2_size_2_coord.first == barrier_1_size_2_coord.first - 1);
    }
    else
    {
        barrier_2_size_2_coord.first = rand()%19 + 1;
    }

    barrier_1_size_1_coord.second = rand()%14 + 3;
    if (barrier_1_size_1_coord.second == barrier_1_size_3_coord.second ||
        barrier_1_size_1_coord.second == barrier_1_size_2_coord.second ||
        barrier_1_size_1_coord.second == barrier_2_size_2_coord.second)
    {
        do
        {
            barrier_1_size_1_coord.first = rand()%19 + 1;
        } while (barrier_1_size_1_coord.first == barrier_1_size_3_coord.first ||
                 barrier_1_size_1_coord.first == barrier_1_size_3_coord.first + 1 ||
                 barrier_1_size_1_coord.first == barrier_1_size_3_coord.first - 1 ||
                 barrier_1_size_1_coord.first == barrier_1_size_2_coord.first ||
                 barrier_1_size_1_coord.first == barrier_1_size_2_coord.first - 1 ||
                 barrier_1_size_1_coord.first == barrier_2_size_2_coord.first ||
                 barrier_1_size_1_coord.first == barrier_2_size_2_coord.first - 1);
    }
    else
    {
        barrier_1_size_1_coord.first = rand()%19 + 1;
    }

    barrier_2_size_1_coord.second = rand()%14 + 3;
    if (barrier_2_size_1_coord.second == barrier_1_size_3_coord.second ||
        barrier_2_size_1_coord.second == barrier_1_size_2_coord.second ||
        barrier_2_size_1_coord.second == barrier_2_size_2_coord.second ||
        barrier_2_size_1_coord.second == barrier_1_size_1_coord.second)
    {
        do
        {
            barrier_2_size_1_coord.first = rand()%19 + 1;
        } while (barrier_2_size_1_coord.first == barrier_1_size_3_coord.first ||
                 barrier_2_size_1_coord.first == barrier_1_size_3_coord.first + 1 ||
                 barrier_2_size_1_coord.first == barrier_1_size_3_coord.first - 1 ||
                 barrier_2_size_1_coord.first == barrier_1_size_2_coord.first ||
                 barrier_2_size_1_coord.first == barrier_1_size_2_coord.first - 1 ||
                 barrier_2_size_1_coord.first == barrier_2_size_2_coord.first ||
                 barrier_2_size_1_coord.first == barrier_2_size_2_coord.first - 1 ||
                 barrier_2_size_1_coord.first == barrier_1_size_1_coord.first);
    }
    else
    {
        barrier_2_size_1_coord.first = rand()%19 + 1;
    }

    barrier_3_size_1_coord.second = rand()%14 + 3;
    if (barrier_3_size_1_coord.second == barrier_1_size_3_coord.second ||
        barrier_3_size_1_coord.second == barrier_1_size_2_coord.second ||
        barrier_3_size_1_coord.second == barrier_2_size_2_coord.second ||
        barrier_3_size_1_coord.second == barrier_1_size_1_coord.second ||
        barrier_3_size_1_coord.second == barrier_1_size_2_coord.second)
    {
        do
        {
            barrier_3_size_1_coord.first = rand()%19 + 1;
        } while (barrier_3_size_1_coord.first == barrier_1_size_3_coord.first ||
                 barrier_3_size_1_coord.first == barrier_1_size_3_coord.first + 1 ||
                 barrier_3_size_1_coord.first == barrier_1_size_3_coord.first - 1 ||
                 barrier_3_size_1_coord.first == barrier_1_size_2_coord.first ||
                 barrier_3_size_1_coord.first == barrier_1_size_2_coord.first - 1 ||
                 barrier_3_size_1_coord.first == barrier_2_size_2_coord.first ||
                 barrier_3_size_1_coord.first == barrier_2_size_2_coord.first - 1 ||
                 barrier_3_size_1_coord.first == barrier_1_size_1_coord.first ||
                 barrier_3_size_1_coord.first == barrier_2_size_1_coord.first);
    }
    else
    {
        barrier_3_size_1_coord.first = rand()%19 + 1;
    }


    for (int i = 0; i<20; i++)
    {
        for (int j = 0; j<20; j++)
        {
            this->ptr[i][j] = NULL;
        }
    }

    this->ptr[blueWarBaseLocation][0] = &blueWarBase;
    this->ptr[yellowWarBaseLocation][19] = &yellowWarBase;

    this->ptr[barrier_1_size_1_coord.first][barrier_1_size_1_coord.second] = &barrier;
    this->ptr[barrier_2_size_1_coord.first][barrier_2_size_1_coord.second] = &barrier;
    this->ptr[barrier_3_size_1_coord.first][barrier_3_size_1_coord.second] = &barrier;
    this->ptr[barrier_1_size_2_coord.first][barrier_1_size_2_coord.second] = &barrier;
    this->ptr[barrier_1_size_2_coord.first - 1][barrier_1_size_2_coord.second] = &barrier;
    this->ptr[barrier_2_size_2_coord.first][barrier_2_size_2_coord.second] = &barrier;
    this->ptr[barrier_2_size_2_coord.first - 1][barrier_2_size_2_coord.second] = &barrier;
    this->ptr[barrier_1_size_3_coord.first][barrier_1_size_3_coord.second] = &barrier;
    this->ptr[barrier_1_size_3_coord.first + 1][barrier_1_size_3_coord.second] = &barrier;
    this->ptr[barrier_1_size_3_coord.first - 1][barrier_1_size_3_coord.second] = &barrier;

    this->ptr[blueUnit_1Coord.first][blueUnit_1Coord.second] = blueUnit_1;
    blueUnit_1->set_coord(blueUnit_1Coord.first,blueUnit_1Coord.second);
    this->ptr[blueUnit_2Coord.first][blueUnit_2Coord.second] = blueUnit_2;
    blueUnit_2->set_coord(blueUnit_2Coord.first,blueUnit_2Coord.second);
    this->ptr[blueUnit_3Coord.first][blueUnit_3Coord.second] = blueUnit_3;
    blueUnit_3->set_coord(blueUnit_3Coord.first,blueUnit_3Coord.second);

    this->ptr[yellowUnit_1Coord.first][yellowUnit_1Coord.second] = yellowUnit_1;
    yellowUnit_1->set_coord(yellowUnit_1Coord.first,yellowUnit_1Coord.second);
    this->ptr[yellowUnit_2Coord.first][yellowUnit_2Coord.second] = yellowUnit_2;
    yellowUnit_2->set_coord(yellowUnit_2Coord.first,yellowUnit_2Coord.second);
    this->ptr[yellowUnit_3Coord.first][yellowUnit_3Coord.second] = yellowUnit_3;
    yellowUnit_3->set_coord(yellowUnit_3Coord.first,yellowUnit_3Coord.second);
}

void Field::move(Unit* soldier)
{
    int temp1,temp2;
    std::pair<int, int> temp = soldier->get_coord();

    int i = 0;
    do
        {
            if(i != 0)
                std::cout << "Некорректный ход" << std::endl;
                std::cout << "Введите строку: ";
                temp1 = Unit::choise(20);
                std::cout << "Введите столбец: ";
                temp2 = Unit::choise(20);
                i++;
        }
    while((ptr[temp1 - 1][temp2 - 1] != NULL && (temp1 != temp.first + 1 || temp2 != temp.second + 1))
          || abs(temp.first - temp1 + 1) > 1 || abs(temp.second - temp2 + 1) > 1
          || temp1 < 1 || temp2 > 20);

    soldier->set_coord(temp1 - 1, temp2 - 1);
    ptr[temp1 - 1][temp2 - 1] = soldier;
    if(temp != soldier->get_coord())
    {
    ptr[temp.first][temp.second] = NULL;
    }
    srand(time(NULL) + temp1);

    if(soldier->get_unit_name() == "Пулеметчик" && soldier->bonus())
    {
        move(soldier);
    }
}


void Field::shoot(Unit* soldier)
{
    Sniper sniper("");
    Stormtrooper stormtr("");
    MachineGunner machinegun("");
    Shotgun gun("");
    Barrier barrier("");
    int temp1,temp2;


    int i = 0;
    do
        {
            if(i != 0)
            {
                std::cout << "Некорректный выстрел" << std::endl;
            }
            std::cout << "Введите строку: ";
            temp1 = Unit::choise(20);
            std::cout << "Введите столбец: ";
            temp2 = Unit::choise(20);
            i++;
        }
    while(abs(soldier->get_coord().first - temp1) > soldier->getRange() || abs(soldier->get_coord().second - temp2) > soldier->getRange());

    int row = abs(soldier->get_coord().first + 1 - temp1);
    int column = abs(soldier->get_coord().second + 1 - temp2);
    int distanse = row >= column ? row : column;
    int min_part = row < column ? row : column;

    int row_inv;
    if(soldier->get_coord().first + 1 - temp1 > 0)
        row_inv = 1;
    else if(soldier->get_coord().first + 1 - temp1 < 0)
        row_inv = -1;
    else
        row_inv = 0;

    int column_inv;
    if(soldier->get_coord().second + 1 - temp2 < 0)
        column_inv = 1;
    else if(soldier->get_coord().second + 1 - temp2 > 0)
        column_inv = -1;
    else
        column_inv = 0;




        for(int k = 1; k <= soldier->getAmmo(); k++)
        {
            srand(time(NULL) + k);
            i = 1 + rand()%(distanse - min_part + 1);
            int critical;
            if(soldier->get_unit_name() == "Автоматчик")
            {
                critical = (int)soldier->bonus() + 1;
            }
            else
            {
                critical = 1;
            }

            bool desolator = soldier->get_unit_name() == "Дробовик";

            if(column == distanse || soldier->get_coord().first + 1 == temp1)
            {
                    bool flag = true;
                    if(flag)
                    {
                    for(int k = 1; k < i; k++)
                    {
                        if(flag)
                        {
                        if(ptr[soldier->get_coord().first][soldier->get_coord().second + k*column_inv] != NULL)
                        {
                            if(typeid(*ptr[soldier->get_coord().first][soldier->get_coord().second + k*column_inv]) == typeid(barrier))
                            {
                                    flag = false;
                                    break;
                            }
                            else if(ptr[soldier->get_coord().first][soldier->get_coord().second + k*column_inv]->get_color() != soldier->get_color())
                            {
                                if(hit(soldier, distanse))
                                {
                                    ptr[soldier->get_coord().first][soldier->get_coord().second + k*column_inv]->get_damage(critical*soldier->getWeapon_damage(), !desolator);
                                    if(!ptr[soldier->get_coord().first][soldier->get_coord().second + k*column_inv]->is_alive())
                                    {
                                        ptr[soldier->get_coord().first][soldier->get_coord().second + k*column_inv] = NULL;
                                    }
                                }
                                flag = false;
                                break;
                            }
                        }
                        }

                    }
                    }
                    if(flag)
                    {
                    for(int j = 1; j <= min_part; j++)
                    {
                        if(flag)
                        {
                        if(ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv] != NULL)
                        {
                            if(typeid(*ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]) == typeid(barrier))
                            {
                                    flag = false;
                                    break;
                            }
                            else if(ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]->get_color() != soldier->get_color())
                            {
                                if(hit(soldier, distanse))
                                {
                                    ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]->get_damage(critical*soldier->getWeapon_damage(), !desolator);
                                    if(!ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]->is_alive())
                                    {
                                        ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv] = NULL;
                                    }
                                }
                                flag = false;
                                break;
                            }
                        }
                        }
                    }
                    }
                    if(flag)
                    {
                    for(int m = 1; m <= distanse - i - min_part + 1; m++)
                    {
                        if(flag)
                        {
                        if(ptr[soldier->get_coord().first - min_part*row_inv][soldier->get_coord().second + (i + min_part - 1 + m)*column_inv] != NULL)
                        {
                            if(typeid(*ptr[soldier->get_coord().first - min_part*row_inv][soldier->get_coord().second + (i + min_part - 1 + m)*column_inv]) == typeid(barrier))
                            {
                                flag = false;
                                break;
                            }
                            else if(ptr[soldier->get_coord().first - min_part*row_inv][soldier->get_coord().second + (i + min_part - 1 + m)*column_inv]->get_color() != soldier->get_color())
                            {
                                if(hit(soldier, distanse))
                                {
                                    ptr[soldier->get_coord().first - min_part*row_inv][soldier->get_coord().second + (i + min_part - 1 + m)*column_inv]->get_damage(critical*soldier->getWeapon_damage(), !desolator);
                                    if(!ptr[soldier->get_coord().first - min_part*row_inv][soldier->get_coord().second + (i + min_part - 1 + m)*column_inv]->is_alive())
                                    {
                                        ptr[soldier->get_coord().first - min_part*row_inv][soldier->get_coord().second + (i + min_part - 1 + m)*column_inv] = NULL;
                                    }
                                }
                                flag = false;
                                break;
                            }
                        }
                        }
                    }
                    }

            }


            else if(row == distanse || soldier->get_coord().second + 1 == temp2)
            {
                    bool flag = true;
                    if(flag)
                    {
                    for(int k = 1; k < i; k++)
                    {
                        if(flag)
                        {
                        if(ptr[soldier->get_coord().first + k*row_inv][soldier->get_coord().second] != NULL)
                        {
                            if(typeid(*ptr[soldier->get_coord().first - k*row_inv][soldier->get_coord().second]) == typeid(barrier))
                            {
                                    flag = false;
                                    break;
                            }
                            else if(ptr[soldier->get_coord().first - k*row_inv][soldier->get_coord().second]->get_color() != soldier->get_color())
                            {
                                if(hit(soldier, distanse))
                                {
                                    ptr[soldier->get_coord().first - k*row_inv][soldier->get_coord().second]->get_damage(critical*soldier->getWeapon_damage(), !desolator);
                                    if(!ptr[soldier->get_coord().first - k*row_inv][soldier->get_coord().second]->is_alive())
                                    {
                                        ptr[soldier->get_coord().first - k*row_inv][soldier->get_coord().second] = NULL;
                                    }
                                }
                                flag = false;
                                break;
                            }
                        }
                        }

                    }
                    }
                    if(flag)
                    {
                    for(int j = 1; j <= min_part; j++)
                    {
                        if(flag)
                        {
                        if(ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv] != NULL)
                        {
                            if(typeid(*ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]) == typeid(barrier))
                            {
                                    flag = false;
                                    break;
                            }
                            else if(ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]->get_color() != soldier->get_color())
                            {
                                if(hit(soldier, distanse))
                                {
                                    ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]->get_damage(critical*soldier->getWeapon_damage(), !desolator);
                                    if(!ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv]->is_alive())
                                    {
                                        ptr[soldier->get_coord().first - j*row_inv][soldier->get_coord().second + (j + i - 1)*column_inv] = NULL;
                                    }
                                }
                                flag = false;
                                break;
                            }
                        }
                        }
                    }
                    }
                    if(flag)
                    {
                    for(int m = 1; m <= distanse - i - min_part + 1; m++)
                    {
                        if(flag)
                        {
                        if(ptr[soldier->get_coord().first - (i + min_part - 1 + m)*row_inv][soldier->get_coord().second + min_part*column_inv] != NULL)
                        {
                            if(typeid(*ptr[soldier->get_coord().first - (i + min_part - 1 + m)*row_inv][soldier->get_coord().second + min_part*column_inv]) == typeid(barrier))
                            {
                                flag = false;
                                break;
                            }
                            else if(ptr[soldier->get_coord().first - (i + min_part - 1 + m)*row_inv][soldier->get_coord().second + min_part*column_inv]->get_color() != soldier->get_color())
                            {
                                if(hit(soldier, distanse))
                                {
                                    ptr[soldier->get_coord().first - (i + min_part - 1 + m)*row_inv][soldier->get_coord().second + min_part*column_inv]->get_damage(critical*soldier->getWeapon_damage(), !desolator);
                                    if(!ptr[soldier->get_coord().first - (i + min_part - 1 + m)*row_inv][soldier->get_coord().second + min_part*column_inv]->is_alive())
                                    {
                                        ptr[soldier->get_coord().first - (i + min_part - 1 + m)*row_inv][soldier->get_coord().second + min_part*column_inv] = NULL;
                                    }
                                }
                                flag = false;
                                break;
                            }
                        }
                        }
                    }
                    }

            }
        }



        if(soldier->get_unit_name() == "Снайпер" && soldier->bonus())
        {
            shoot(soldier);
        }

}


bool Field::hit(Unit* soldier, int range)
{
    int chance = (int)(((double)(soldier->getAccuracy())/100)*(100 - range*3));

    int temp = 1 + rand()%100;
    return temp > chance ? false : true;
}
