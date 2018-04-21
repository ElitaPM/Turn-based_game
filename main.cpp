#include <iostream>
#include "field.h"
#include "menu.h"
#include "unit.h"
#include "warbase.h"


using namespace std;

int main()
{
    Menu menu;
    Field field;
    Barrier barrier;
    Sniper sniper1(""), sniper2(""),sniper3(""), sniper4(""),sniper5("");
    MachineGunner gunner("");
    Unit* ptrs[6] = {&sniper1,&sniper2,&sniper3,&sniper4,&sniper5,&gunner};
    WarBase wb1,wb2;

    field.init(ptrs[0], ptrs[1], ptrs[2], ptrs[3], ptrs[4], ptrs[5], wb1, wb2, barrier);
    menu.print(field);
    menu.print();

    cout << ptrs[0]->get_coord().first << " " << ptrs[0]->get_coord().second << endl;

    field.move(ptrs[0]);
  //  menu.print(field);
    field.printsuka();
    menu.print();

    cout << ptrs[0]->get_coord().first << " " << ptrs[0]->get_coord().second << endl;

    return 0;

}
