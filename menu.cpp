#include "menu.h"

Menu::Menu()
{
    for (int j = 0; j <= 20; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            field[2*j][i*4] = '+';
            field[2*j][i*4+1] = '-';
            field[2*j][i*4+2] = '-';
            field[2*j][i*4+3] = '-';
        }
        field [2*j][80] = '+';
        field [2*j][81] = '\n';

        if (j != 20)
        {
            for (int k = 0; k < 20; k++)
            {
                field[2*j+1][k*4] = '|';
                field[2*j+1][k*4+1] = ' ';
                field[2*j+1][k*4+2] = ' ';
                field[2*j+1][k*4+3] = ' ';
            }
            field [2*j+1][80] = '|';
            field [2*j+1][81] = '\n';
        }

    }
}

void Menu::print(Field &field)
{
    std::vector<std::vector<char>> bukafki;
    bukafki.reserve(20);
            field.units_simbol(bukafki);

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            if ((bukafki[j])[i] == 'O' || (bukafki[j])[i] == 'B')
            {
                this->field[1+2*j][2+4*i-1] = '|';
                this->field[1+2*j][2+4*i] = '|';
                this->field[1+2*j][2+4*i+1] = '|';
            }

            else
            {
                this->field[1+2*j][2+4*i] = (bukafki[j])[i];
            }
        }

    }
    bukafki.clear();
}

void Menu::print()
{
    for (int j=0; j<41; j++)
    {
        for (int i=0; i<82; i++)
        {
            std::cout << this->field[j][i];
        }
    }
}


