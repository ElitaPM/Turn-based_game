#ifndef UNIT_H
#define UNIT_H
#include <utility>



class Unit
{
private:
    std::pair <int, int> coord;
public:
    Unit();
    virtual bool is_alive() = 0;
    void set_coord(int first, int second);
    std::pair<int, int> get_coord();
};

#endif // UNIT_H
