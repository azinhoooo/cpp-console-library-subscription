
#ifndef SORT_H
#define SORT_H

#include "conference_programm.h"

// Функции сортировки
void heap_sort(conference_programm* array[], int size, int (*compare)(const conference_programm*, const conference_programm*));
void merge_sort(conference_programm* array[], int size, int (*compare)(const conference_programm*, const conference_programm*));

// Функции сравнения
int compare_by_duration(const conference_programm* a, const conference_programm* b);
int compare_by_author_and_title(const conference_programm* a, const conference_programm* b);

#endif // SORT_H
