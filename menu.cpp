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
        field [2*j][81] = ' ';
        field [2*j][82] = ' ';
        field [2*j][83] = '\n';

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
            if(j < 9)
            {
                field [2*j+1][81] = '0' + (char)(j + 1);
                field [2*j+1][82] = ' ';
            }
            else
            {
                field [2*j+1][81] = '0' + (char)((j + 1)/10);
                field [2*j+1][82] = '0' + (char)((j + 1)%10);
            }

            field [2*j+1][83] = '\n';
        }

    }
}

void Menu::print(Field &field)
{
    char** symbols = new char*[20];
    for (int j = 0; j < 20; j++)
        {
            symbols[j] = new char[20];
        }

    field.units_simbol(symbols);

    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            if (symbols[j][i] == 'O' || symbols[j][i] == 'B')
            {
                this->field[1+2*j][2+4*i-1] = '|';
                this->field[1+2*j][2+4*i] = '|';
                this->field[1+2*j][2+4*i+1] = '|';
            }

            else
            {
                this->field[1+2*j][2+4*i] = symbols[j][i];
            }
        }

    }
    for (int j = 0; j < 20; j++)
    {
        delete[] symbols[j];
    }
    delete[] symbols;

}

void Menu::print()
{
    for (int j=0; j < 20; j++)
    {
        std::cout << std::setw(2) << ' ';
        std::cout << std::setw(2) << std::left << j + 1;
    }
    std::cout << std::endl;
    for (int j=0; j < 41; j++)
    {
        for (int i=0; i < 84; i++)
        {
            std::cout << field[j][i];
        }
    }
}
