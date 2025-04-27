#include <stdlib.h>
#include <stdio.h>

/* Escreva uma func¸˜ao recursiva que realiza a multiplicac¸˜ao
de dois n ´umeros inteiros por meio da estrat ´egia de somas
sucessivas. */

void main(){
    int mult(int a, int b){
        if(b == 0)
            return 0;
        if(b > 0){
            return a + mult(a, b - 1);
        }
    }
    5, 2
    

    printf("%d", mult(5, 2));

}