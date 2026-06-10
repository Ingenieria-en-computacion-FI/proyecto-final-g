#include "algorithms.h"

int incremental_sum(int* array, int size) {
    if (array == 0 || size <= 0)
        return 0;

    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += array[i];

    return sum;
}
