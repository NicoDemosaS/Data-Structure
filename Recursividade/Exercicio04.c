#include <stdlib.h>
#include <stdio.h>
/*Escreva uma func¸˜ao recursiva que calcule o MDC de dois
n´umeros naturais a e b usando o algoritmo de Euclides. */
int mdc(int a, int b){
    if(b==0)
        return a;
    if(b > 0)
        return mdc(b, a % b);
}
void main(){
    printf("%d",mdc(15, 12)); //Out put esperado -> 3
}