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

void Menu::print(Unit **blue_unit, Unit **yellow_unit)
{
    std::cout << "\x1B[2J\x1B[H";

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
            if (j == 1 && i == 82)
            {
                std::cout << "   Blue unit 1 HP: ";  blue_unit[0]->showHP(); std::cout << "   ";
                std::cout << "Yellow unit 1 HP: "; yellow_unit[0]->showHP();
            }
            else if (j == 3 && i == 82)
            {
                std::cout << "   Blue unit 2 HP: ";  blue_unit[1]->showHP(); std::cout << "   ";
                std::cout << "Yellow unit 2 HP: "; yellow_unit[1]->showHP();
            }
            else if (j == 5 && i == 82)
            {
                std::cout << "   Blue unit 3 HP: ";  blue_unit[2]->showHP(); std::cout << "   ";
                std::cout << "Yellow unit 3 HP: "; yellow_unit[2]->showHP();
            }
        }
    }
}


void Menu::units_choise() const
{
    std::cout << "Выберите расстановку сил: " << std::endl;
    std::cout << "1)  3 Снайпера " << std::endl;
    std::cout << "2)  3 Автоматчика " << std::endl;
    std::cout << "3)  3 Пулеметчика " << std::endl;
    std::cout << "4)  3 Дробовика " << std::endl;
    std::cout << "5)  2 Снайпера + Автоматчик " << std::endl;
    std::cout << "6)  2 Снайпера + Пулеметчик " << std::endl;
    std::cout << "7)  2 Снайпера + Дробовик " << std::endl;
    std::cout << "8)  2 Автоматчика + Снайпер " << std::endl;
    std::cout << "9)  2 Автоматчика + Пулеметчик " << std::endl;
    std::cout << "10) 2 Автоматчика + Дробовик " << std::endl;
    std::cout << "11) 2 Пулеметчика + Снайпер " << std::endl;
    std::cout << "12) 2 Пулеметчика + Автоматчик " << std::endl;
    std::cout << "13) 2 Пулеметчика + Дробовик " << std::endl;
    std::cout << "14) 2 Дробовика + Снайпер " << std::endl;
    std::cout << "15) 2 Дробовика + Автоматчик " << std::endl;
    std::cout << "16) 2 Дробовика + Пулеметчик " << std::endl;
    std::cout << "17) Снайпер + Автоматчик + Пулеметчик " << std::endl;
    std::cout << "18) Снайпер + Автоматчик + Дробовик " << std::endl;
    std::cout << "19) Снайпер + Пулеметчик + Дробовик " << std::endl;
    std::cout << "20) Автоматчик + Пулеметчик + Дробовик " << std::endl;
}
