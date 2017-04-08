#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y) {
    int * sum;
    bool check_overflow = __builtin_add_overflow(x, y, sum);
}
