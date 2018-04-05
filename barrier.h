#ifndef BARRIER_H
#define BARRIER_H
#include <vector>
#include <utility>
#include "unit.h"

using namespace std;

class Barrier: public Unit
{
private:
    int Size;
public:
    Barrier(int Size): Unit(){}
    bool is_alive();
    vector<pair<int,int> > shape();
};

#endif // BARRIER_H
