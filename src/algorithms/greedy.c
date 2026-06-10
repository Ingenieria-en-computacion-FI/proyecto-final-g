#include "algorithms.h"

int greedy_max_value(int* array, int size) {
    if (array == 0 || size <= 0)
        return -1;

    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}
