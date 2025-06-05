#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int ehPotenciaDeDois(int n, int k){

    if(math(2, k) > n)
        return 0;
    if(math(2, k) ==  0)
        return 1;
    return ehPotenciaDeDois(n, k+1);
}