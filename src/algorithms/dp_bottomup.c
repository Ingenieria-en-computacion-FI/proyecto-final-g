#include <stdlib.h>
#include "algorithms.h"

int dp_fibonacci_bottomup(int n) {
    if (n < 0)
        return -1;

    if (n <= 1)
        return n;

    int* dp = malloc(sizeof(int) * (n + 1));

    if (dp == 0)
        return -1;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    int result = dp[n];

    free(dp);

    return result;
}
