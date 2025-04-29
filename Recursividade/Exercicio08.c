#include <stdio.h>
#include <stdlib.h>

/* M ´etodo da Multiplicac¸˜ao Russa. O m ´etodo da multiplica c¸˜ao
Russa consiste em:
a) Escreva os n ´umeros a e b que se deseja multiplicar
na parte superior de duas colunas A e B.
b) Divida a por 2 sucessivamente ignorando o resto
at ´e obter o quociente 1, e escreva cada resultado em
um linha da coluna A.
c) Multiplique b por 2 tantas vezes quantas se haja
dividido a por 2 e escreva cada resultado na linha
da coluna B.
d) Some todos os n ´umeros da coluna B que estejam ao
lado de um n´umero ´ımpar da coluna A.*/

int russa(int a, int b){
    printf("A:%d B: %d\n", a, b);
    if(a == 1)
        return b;
    if(a > 1 && a % 2 == 0)
        return russa(a/2, b * 2);
    if(a > 1 && a % 2 != 0)
        return b + russa(a/2, b * 2);
}


void main(){
    printf("%d", russa(27, 82));
}