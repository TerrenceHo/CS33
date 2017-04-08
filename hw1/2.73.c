#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y){
    int sum = (unsigned int) x + (unsigned int) y;
    int posO = ( ~(x & INT_MIN) & ~(y & INT_MIN) & (sum & INT_MIN) );
    int negO = ( (x & INT_MIN) & (y & INT_MIN) & ~(sum & INT_MIN));
    (posO) && (sum=INT_MAX);
    (negO) && (sum=INT_MIN);
    return sum;
}