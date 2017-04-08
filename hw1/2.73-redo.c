#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y){
    int sum = 0;
    int * ptr = &sum;
    int check = (int) __builtin_add_overflow(x, y, ptr);
    int mask = 1 << ((sizeof(int) << 3 ) - 1);
    int sum_msb = mask & sum;
    (check) && (sum_msb == INT_MIN) && (sum=INT_MAX);
    (check) && (sum_msb == 0) && (sum=INT_MIN);
    return sum;
}