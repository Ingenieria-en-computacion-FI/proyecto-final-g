#include <stdlib.h>
#include "algorithms.h"

static int fib_td(int n, int* memo) {
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fib_td(n - 1, memo) + fib_td(n - 2, memo);

    return memo[n];
}

int dp_fibonacci_topdown(int n) {
    if (n < 0)
        return -1;

    int* memo = malloc(sizeof(int) * (n + 1));

    if (memo == 0)
        return -1;

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    int result = fib_td(n, memo);

    free(memo);

    return result;
}
