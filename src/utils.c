#include "utils.h"

#include <stdlib.h>


void shuffle(int *array, int size)
{
    int rand_idx, temp;

    for(int i = size - 1; i > 0; i--)
    {
        rand_idx = rand() % (i + 1);
        temp = array[i];
        array[i] = array[rand_idx];
        array[rand_idx] = temp;
    }
}