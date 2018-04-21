#ifndef BARRIER_H
#define BARRIER_H
#include <vector>
#include <utility>
#include "unit.h"

using namespace std;

class Barrier: public Unit
{
public:
    Barrier(): Unit(){}
    bool is_alive() {};
};

#endif // BARRIER_H
