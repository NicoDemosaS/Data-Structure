#include <stdlib.h>
#include <stdio.h>

int ocorr(int k, int n){
    if(n == 0 && k != 0)
        return 0;
    if((n % 10) == k)
        return 1 + ocorr(k, n/10);
    if((n % 10) != k)
        return 0 + ocorr(k, n/10);
}

void main(){
    printf("%d", ocorr(5, 50725));
}