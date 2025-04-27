#include <stdio.h>
#include <stdlib.h>

int hs(int n){
    if(n==1)
        return 1;
    if((n % 2) == 0)
        return n + hs(n/2);
    if((n % 2 != 0))
        return n + hs((n * 3) + 1);
}

void main(){
    printf("%d", hs(3));
}