#include <iostream>
#include <iomanip>
#include "file_reader.h"
#include "conference_programm.h"
#include "constants.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №2. Программа конференции\n";
    cout << "Автор: Сергей Радевич\n\n";

    conference_programm* programs[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", programs, size);
        cout << "***** Программа конференции *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод времени начала **********/
            cout << "Время начала....: ";
            cout << setw(2) << setfill('0') << programs[i]->start.hour << ':';
            cout << setw(2) << setfill('0') << programs[i]->start.minute;
            cout << '\n';

            /********** вывод времени окончания **********/
            cout << "Время окончания.: ";
            cout << setw(2) << setfill('0') << programs[i]->finish.hour << ':';
            cout << setw(2) << setfill('0') << programs[i]->finish.minute;
            cout << '\n';

            /********** вывод автора **********/
            cout << "Автор...........: ";
            // вывод фамилии
            cout << programs[i]->author.last_name << " ";
            // вывод первой буквы имени
            cout << programs[i]->author.first_name[0] << ". ";
            // вывод первой буквы отчества
            cout << programs[i]->author.middle_name[0] << ".";
            cout << '\n';

            /********** вывод названия доклада **********/
            cout << "Название........: ";
            cout << '"' << programs[i]->title << '"';
            cout << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete programs[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
 

