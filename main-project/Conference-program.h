#ifndef CONFERENCE-PROGRAM.H
#define CONFERENCE-PROGRAM.H

#include "constants.h"

struct Time
{
    int hour;
    int minute;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct conference_programm
{
    Time start;
    Time finish;
    person author;
    char title[MAX_STRING_SIZE];
};

#endif
