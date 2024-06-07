#include <iostream>
#include <cstring>

#include "filter.h"
#include "conference_programm.h"

int duration(conference_programm* element)
{
    int start_minutes = element->start.hour * 60 + element->start.minute;
    int finish_minutes = element->finish.hour * 60 + element->finish.minute;
    return finish_minutes - start_minutes;
}

conference_programm** filter(conference_programm* array[], int size, bool (*check)(conference_programm* element), int& result_size)
{
    conference_programm** result = new conference_programm * [size];
    result_size = 0;
    for (int i = 0; i < size; i++)
    {
        if (check(array[i]))
        {
            result[result_size++] = array[i];
        }
    }
    return result;
}

bool check_conference_programm_by_name(conference_programm* element)
{
    return strcmp(element->author.first_name, "mobile") == 0 && strcmp(element->author.middle_name, "") == 0 && strcmp(element->author.last_name, "") == 0;
}

bool check_conference_programm_by_duration(conference_programm* element)
{
    return duration(element) > 15;
}