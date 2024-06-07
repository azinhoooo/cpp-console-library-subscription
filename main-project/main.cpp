#include <iostream>
#include <iomanip>
#include "file_reader.h"
#include "conference_programm.h"
#include "constants.h"
#include "sort.h"

using namespace std;

// Функция для отображения меню и получения выбора пользователя
int displayMenu(const string options[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << options[i] << '\n';
    }
    int choice;
    cout << "Выберите вариант: ";
    cin >> choice;
    return choice - 1; // возврат индекса
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №4. GIT\n";
    cout << "Вариант №2. Программа конференции\n";
    cout << "Автор: Сергей Радевич\n";
    cout << "Группа: 23ПИ1д\n";
    conference_programm* programs[MAX_FILE_ROWS_COUNT];
    int size;
    try {
        read("data.txt", programs, size);

        const string sortMethods[] = { "Пирамидальная сортировка", "Сортировка слиянием" };
        const string compareMethods[] = { "По убыванию длительности доклада", "По возрастанию фамилии автора доклада, а в рамках одного автора по возрастанию темы доклада" };

        cout << "Выберите метод сортировки:\n";
        int sortMethodIndex = displayMenu(sortMethods, 2);

        cout << "Выберите критерий сортировки:\n";
        int compareMethodIndex = displayMenu(compareMethods, 2);

        // Массив указателей на функции сортировки
        void (*sortFunctions[])(conference_programm * [], int, int (*)(const conference_programm*, const conference_programm*)) = { heap_sort, merge_sort };

        // Массив указателей на функции сравнения
        int (*compareFunctions[])(const conference_programm*, const conference_programm*) = { compare_by_duration, compare_by_author_and_title };

        // Вызов функции сортировки с выбранной функцией сравнения
        sortFunctions[sortMethodIndex](programs, size, compareFunctions[compareMethodIndex]);

        cout << "***** Программа конференции *****\n\n";
        for (int i = 0; i < size; i++) {
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
        for (int i = 0; i < size; i++) {
            delete programs[i];
        }
    }
    catch (const char* error) {
        cout << error << '\n';
    }

    cout << "Laboratory work #4. GIT\n";
    cout << "Variant #2. Conference program\n";
    cout << "Author: Sergey Radevich\n";
    cout << "Group: 23PI1d\n";

    return 0;
}
 

