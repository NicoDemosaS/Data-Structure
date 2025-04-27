#include <stdio.h>
#include <stdlib.h>
/*1. Considere um sistema num ´erico que n ˜ao tenha a operac¸˜ao
de adi c¸˜ao implementada e que tal sistema disp ˜oe so-
mente das fun c¸˜oes sucessor e antecessor. Com base nestas
duas func¸˜oes, escreva uma func¸˜ao recursiva soma(x,y) em
C que calcule a soma de dois n ´umeros inteiros (x e y)
utilizando somente as duas fun c¸˜oes mencionadas. Im-
plemente tamb ´em as func¸˜oes sucessor e antecessor, as quais
podem utilizar o operador de adic¸˜ao. */


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