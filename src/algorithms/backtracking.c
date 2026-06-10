#include "algorithms.h"

static int subset_sum_recursive(int* array, int index, int size, int target) {
    if (target == 0)
        return 1;

    if (index >= size || target < 0)
        return 0;

    if (subset_sum_recursive(array, index + 1, size, target - array[index]))
        return 1;

    return subset_sum_recursive(array, index + 1, size, target);
}

int backtracking_subset_sum(int* array, int size, int target) {
    if (array == 0 || size < 0)
        return 0;

    return subset_sum_recursive(array, 0, size, target);
}
