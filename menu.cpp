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
            if (symbols[j][i] == 'O')
            {
                this->field[1+2*j][2+4*i-1] = '|';
                this->field[1+2*j][2+4*i] = '|';
                this->field[1+2*j][2+4*i+1] = '|';
            }
            else if (symbols[j][i] == 'B')
            {
                this->field[1+2*j][2+4*i-1] = 'B';
                this->field[1+2*j][2+4*i] = 'B';
                this->field[1+2*j][2+4*i+1] = 'B';
            }
            else if (symbols[j][i] == 'b')
            {
                this->field[1+2*j][2+4*i-1] = 'b';
                this->field[1+2*j][2+4*i] = 'b';
                this->field[1+2*j][2+4*i+1] = 'b';
            }
            else if (symbols[j][i] == 'S')
            {
                this->field[1+2*j][2+4*i] = 'S';
            }
            else if (symbols[j][i] == 's')
            {
                this->field[1+2*j][2+4*i] = 's';
            }
            else if (symbols[j][i] == 'A')
            {
                this->field[1+2*j][2+4*i] = 'A';
            }
            else if (symbols[j][i] == 'a')
            {
                this->field[1+2*j][2+4*i] = 'a';
            }
            else if (symbols[j][i] == 'P')
            {
                this->field[1+2*j][2+4*i] = 'P';
            }
            else if (symbols[j][i] == 'p')
            {
                this->field[1+2*j][2+4*i] = 'p';
            }
            else if (symbols[j][i] == 'G')
            {
                this->field[1+2*j][2+4*i] = 'G';
            }
            else if (symbols[j][i] == 'g')
            {
                this->field[1+2*j][2+4*i] = 'g';
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



void Menu::print(Unit **blue_unit, Unit **yellow_unit, Unit* blue_base, Unit* yellow_base)
{
    std::cout << "\x1B[2J\x1B[H";

    for (int j = 0; j < 20; j++)
    {
        std::cout << std::setw(2) << ' ';
        std::cout << std::setw(2) << std::left << j + 1;
    }

    std::cout << std::endl;
    for (int j = 0; j < 41; j++)
    {
        for (int i=0; i < 84; i++)
        {

            if (field[j][i] == 'B')
            {
                std::cout << "\033[34m|\033[0m";
            }
            else if (field[j][i] == 'b')
            {
                std::cout << "\033[33m|\033[0m";
            }
            else if (field[j][i] == 'S')
            {
                std::cout << "\033[34mS\033[0m";
            }
            else if (field[j][i] == 's')
            {
                std::cout << "\033[33mS\033[0m";
            }
            else if (field[j][i] == 'A')
            {
                std::cout << "\033[34mA\033[0m";
            }
            else if (field[j][i] == 'a')
            {
                std::cout << "\033[33mA\033[0m";
            }
            else if (field[j][i] == 'P')
            {
                std::cout << "\033[34mP\033[0m";
            }
            else if (field[j][i] == 'p')
            {
                std::cout << "\033[33mP\033[0m";
            }
            else if (field[j][i] == 'G')
            {
                std::cout << "\033[34mG\033[0m";
            }
            else if (field[j][i] == 'g')
            {
                std::cout << "\033[33mG\033[0m";
            }
            else
            {
                std::cout << field[j][i];
            }



            if (j == 1 && i == 82)
            {
                std::cout << "   " << "\033[34mBlue team:\033[0m";
            }
            else if (j == 3 && i == 82)
            {
                std::cout << "   " << blue_base->get_unit_name() << "(" <<blue_base->get_coord().first + 1 <<
                "," <<blue_base->get_coord().second + 1 << ") HP: ";  blue_base->showHP();
            }
            else if (j == 5 && i == 82)
            {
                std::cout << "   Unit 1 - " << blue_unit[0]->get_unit_name() << "(" <<blue_unit[0]->get_coord().first + 1 <<
                "," <<blue_unit[0]->get_coord().second + 1 << ") HP: ";  blue_unit[0]->showHP();
            }
            else if (j == 7 && i == 82)
            {
                std::cout << "   Unit 2 - " << blue_unit[1]->get_unit_name() << "(" <<blue_unit[1]->get_coord().first + 1 <<
                "," <<blue_unit[1]->get_coord().second + 1 << ") HP: ";  blue_unit[1]->showHP();
            }
            else if (j == 9 && i == 82)
            {
                std::cout << "   Unit 3 - " << blue_unit[2]->get_unit_name() << "(" <<blue_unit[2]->get_coord().first + 1 <<
                "," <<blue_unit[2]->get_coord().second + 1 << ") HP: ";  blue_unit[2]->showHP();
            }
            if (j == 13 && i == 82)
            {
                std::cout << "   " << "\033[33mYellow team:\033[0m";
            }
            else if (j == 15 && i == 82)
            {
                std::cout << "   " << yellow_base->get_unit_name() << "(" <<yellow_base->get_coord().first + 1 <<
                "," <<yellow_base->get_coord().second + 1 << ") HP: ";  yellow_base->showHP();
            }
            else if (j == 17 && i == 82)
            {
                std::cout << "   Unit 1 - " << yellow_unit[0]->get_unit_name() << "(" <<yellow_unit[0]->get_coord().first + 1 <<
                "," <<yellow_unit[0]->get_coord().second + 1 << ") HP: ";  yellow_unit[0]->showHP();
            }
            else if (j == 19 && i == 82)
            {
                std::cout << "   Unit 2 - " << yellow_unit[1]->get_unit_name() << "(" <<yellow_unit[1]->get_coord().first + 1 <<
                "," <<yellow_unit[1]->get_coord().second + 1 << ") HP: ";  yellow_unit[1]->showHP();
            }
            else if (j == 21 && i == 82)
            {
                std::cout << "   Unit 3 - " << yellow_unit[2]->get_unit_name() << "(" <<yellow_unit[2]->get_coord().first + 1 <<
                "," <<yellow_unit[2]->get_coord().second + 1 << ") HP: ";  yellow_unit[2]->showHP();
            }
        }
    }
}
