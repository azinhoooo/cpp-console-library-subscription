#include <iostream>
#include <iomanip>
#include "file_reader.h"
#include "conference_programm.h"
#include "constants.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �4. GIT\n";
    cout << "������� �2. ��������� �����������\n";
    cout << "�����: ������ �������\n\n";

    conference_programm* programs[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", programs, size);
        cout << "***** ��������� ����������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
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
 

