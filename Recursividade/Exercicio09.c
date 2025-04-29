#include <stdio.h>

/* 9. Escreva uma func¸˜ao recursiva que verifica se um dado
n ´umero ´e primo ou n ˜ao. Dica: Al ´em do par ˆametro do
n ´umero que deve ser verificado se ´e primo, considere
o recebimento de outro par ˆametro que indicar ´a qual o
divisor atual que est´a sendo testado.*/

int SerPrimo(int a, int divisor){
    if(divisor == a)
        return 1; // E PRIMO

    if(a % divisor == 0)
        return 0; // CASO BASE, NAO E PRIMO

    return SerPrimo(a, divisor + 1);
        
}

void main(){
    printf("%d\n", SerPrimo(347, 2));

}