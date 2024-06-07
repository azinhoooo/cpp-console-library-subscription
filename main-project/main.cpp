#include <iostream>
#include <iomanip>
#include "file_reader.h"
#include "conference_programm.h"
#include "constants.h"
#include "sort.h"

using namespace std;

// ������� ��� ����������� ���� � ��������� ������ ������������
int displayMenu(const string options[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << options[i] << '\n';
    }
    int choice;
    cout << "�������� �������: ";
    cin >> choice;
    return choice - 1; // ������� �������
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �4. GIT\n";
    cout << "������� �2. ��������� �����������\n";
    cout << "�����: ������ �������\n";
    cout << "������: 23��1�\n";
    conference_programm* programs[MAX_FILE_ROWS_COUNT];
    int size;
    try {
        read("data.txt", programs, size);

        const string sortMethods[] = { "������������� ����������", "���������� ��������" };
        const string compareMethods[] = { "�� �������� ������������ �������", "�� ����������� ������� ������ �������, � � ������ ������ ������ �� ����������� ���� �������" };

        cout << "�������� ����� ����������:\n";
        int sortMethodIndex = displayMenu(sortMethods, 2);

        cout << "�������� �������� ����������:\n";
        int compareMethodIndex = displayMenu(compareMethods, 2);

        // ������ ���������� �� ������� ����������
        void (*sortFunctions[])(conference_programm * [], int, int (*)(const conference_programm*, const conference_programm*)) = { heap_sort, merge_sort };

        // ������ ���������� �� ������� ���������
        int (*compareFunctions[])(const conference_programm*, const conference_programm*) = { compare_by_duration, compare_by_author_and_title };

        // ����� ������� ���������� � ��������� �������� ���������
        sortFunctions[sortMethodIndex](programs, size, compareFunctions[compareMethodIndex]);

        cout << "***** ��������� ����������� *****\n\n";
        for (int i = 0; i < size; i++) {
            /********** ����� ������� ������ **********/
            cout << "����� ������....: ";
            cout << setw(2) << setfill('0') << programs[i]->start.hour << ':';
            cout << setw(2) << setfill('0') << programs[i]->start.minute;
            cout << '\n';

            /********** ����� ������� ��������� **********/
            cout << "����� ���������.: ";
            cout << setw(2) << setfill('0') << programs[i]->finish.hour << ':';
            cout << setw(2) << setfill('0') << programs[i]->finish.minute;
            cout << '\n';

            /********** ����� ������ **********/
            cout << "�����...........: ";
            // ����� �������
            cout << programs[i]->author.last_name << " ";
            // ����� ������ ����� �����
            cout << programs[i]->author.first_name[0] << ". ";
            // ����� ������ ����� ��������
            cout << programs[i]->author.middle_name[0] << ".";
            cout << '\n';

            /********** ����� �������� ������� **********/
            cout << "��������........: ";
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
 

