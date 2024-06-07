#include "sort.h"
#include <cstring>
#include <algorithm> // Для std::swap

// Функция для вычисления длительности
int duration(const conference_programm* element)
{
    int start_minutes = element->start.hour * 60 + element->start.minute;
    int finish_minutes = element->finish.hour * 60 + element->finish.minute;
    return finish_minutes - start_minutes;
}

// Функции сравнения
int compare_by_duration(const conference_programm* a, const conference_programm* b)
{
    return duration(b) - duration(a); // По убыванию длительности
}

int compare_by_author_and_title(const conference_programm* a, const conference_programm* b)
{
    int cmp = strcmp(a->author.last_name, b->author.last_name);
    if (cmp == 0)
    {
        cmp = strcmp(a->title, b->title);
    }
    return cmp;
}

// Вспомогательные функции для сортировки слиянием
void merge(conference_programm* array[], conference_programm* left[], int left_size, conference_programm* right[], int right_size, int (*compare)(const conference_programm*, const conference_programm*))
{
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
    {
        if (compare(left[i], right[j]) <= 0)
        {
            array[k++] = left[i++];
        }
        else
        {
            array[k++] = right[j++];
        }
    }
    while (i < left_size)
    {
        array[k++] = left[i++];
    }
    while (j < right_size)
    {
        array[k++] = right[j++];
    }
}

void merge_sort(conference_programm* array[], int size, int (*compare)(const conference_programm*, const conference_programm*))
{
    if (size < 2) return;

    int mid = size / 2;
    conference_programm** left = new conference_programm * [mid];
    conference_programm** right = new conference_programm * [size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = array[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = array[i];
    }

    merge_sort(left, mid, compare);
    merge_sort(right, size - mid, compare);
    merge(array, left, mid, right, size - mid, compare);

    delete[] left;
    delete[] right;
}

// Вспомогательные функции для пирамидальной сортировки
void heapify(conference_programm* array[], int size, int root, int (*compare)(const conference_programm*, const conference_programm*))
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && compare(array[left], array[largest]) > 0)
    {
        largest = left;
    }
    if (right < size && compare(array[right], array[largest]) > 0)
    {
        largest = right;
    }
    if (largest != root)
    {
        std::swap(array[root], array[largest]);
        heapify(array, size, largest, compare);
    }
}

void heap_sort(conference_programm* array[], int size, int (*compare)(const conference_programm*, const conference_programm*))
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i, compare);
    }
    for (int i = size - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]);
        heapify(array, i, 0, compare);
    }
}