#ifndef UNIT_H
#define UNIT_H


class Unit
{
private:
    int HP;
    int armor;
public:
    Unit();
    virtual bool is_alive() = 0;
};

#endif // UNIT_H
