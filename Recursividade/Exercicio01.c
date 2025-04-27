#include <stdio.h>
#include <stdlib.h>

void main(){

    int soma(int x, int y){
        if(y == 0)
            return x;
        if(y > 0){
            return soma(x+1, y-1);
        }
    }
   
    printf("%d", soma(5, 5));






}