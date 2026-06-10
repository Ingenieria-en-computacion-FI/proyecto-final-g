#include "algorithms.h"

int divide_conquer_sum(int* array, int left, int right) {
    if (array == 0 || left > right)
        return 0;

    if (left == right)
        return array[left];

    int mid = left + (right - left) / 2;

    return divide_conquer_sum(array, left, mid) +
           divide_conquer_sum(array, mid + 1, right);
}
