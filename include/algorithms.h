#ifndef ALGORITHMS_H
#define ALGORITHMS_H

int brute_force_search(int* array, int size, int target);
int greedy_max_value(int* array, int size);
int backtracking_subset_sum(int* array, int size, int target);
int divide_conquer_sum(int* array, int left, int right);
int dp_fibonacci_topdown(int n);
int dp_fibonacci_bottomup(int n);
int incremental_sum(int* array, int size);

#endif