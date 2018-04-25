#ifndef BARRIER_H
#define BARRIER_H
#include <vector>
#include <utility>
#include "unit.h"



class Barrier: public Unit
{
public:
    Barrier(std::string color): Unit(color){}
    void bonus(){}
};

#endif // BARRIER_H
