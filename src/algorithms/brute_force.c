#include "algorithms.h"

int brute_force_search(int* array, int size, int target) {
    if (array == 0 || size <= 0)
        return -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == target)
            return i;
    }

    return -1;
}
