#include "field.h"
#include "unit.h"
#include "warbase.h"
#include "barrier.h"
#include <typeinfo>
#include "soldier.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Field::Field()
{

}

void Field::units_simbol(std::vector<std::vector<char>>& vec)
{
    Barrier barrier;
    WarBase base;
    Sniper sniper("");
    Stormtrooper stormtr("");
    MachineGunner machinegun("");
    Shotgun gun("");
    for (int j=0; j<20; j++)
    {
        for (int i=0; i<20; i++)
        {
            if (this->ptr[j][i] != NULL)
            {
                if (typeid(*this->ptr[j][i]) == typeid(sniper))
                {
                    vec[j].push_back('S');
                }
                else if (typeid(*this->ptr[j][i]) == typeid(stormtr))
                {
                    vec[j].push_back('A');
                }
                else if (typeid(*this->ptr[j][i]) == typeid(machinegun))
                {
                    vec[j].push_back('P');
                }
                else if (typeid(*this->ptr[j][i]) == typeid(gun))
                {
                    vec[j].push_back('G');
                }
                else if (typeid(*this->ptr[j][i]) == typeid(base))
                {
                    vec[j].push_back('B');
                }
                else if (typeid(*this->ptr[j][i]) == typeid(barrier))
                {
                    vec[j].push_back('O');
                }
            }
            else
            {
                vec[j].push_back(' ');
            }
        }
    }
}

void Field::init(Unit* yellowUnit_1,
                Unit* yellowUnit_2,
                Unit* yellowUnit_3,
                Unit* blueUnit_1,
                Unit* blueUnit_2,
                Unit* blueUnit_3,
                WarBase& blueWarBase,
                WarBase& yellowWarBase, Barrier &barrier)
{

    srand(time(NULL));

    int blueWarBaseLocation = rand()%20;
    int yellowWarBaseLocation = rand()%20;
    pair<int , int> blueUnit_1Coord, blueUnit_2Coord, blueUnit_3Coord, yellowUnit_1Coord, yellowUnit_2Coord, yellowUnit_3Coord;


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

    pair <int,int> barrier_1_size_3_coord,
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
    std::cout << "Введите строку: ";
    std::cin >> temp1;
    std::cout << "Введите столбец: ";
    std::cin >> temp2;

    soldier->set_coord(temp1, temp2);
    this->ptr[temp1][temp2] = soldier;
    this->ptr[temp.first][temp.second] = NULL;
}
