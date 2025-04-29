#include <stdio.h>

/*10. Escreva uma fun c¸˜ao recursiva que inverte um n ´umero
inteiro, ou seja, se o n ´umero dado ´e 625, a fun c¸˜ao deve
retornar 526*/

int inverter(int a){
    int b;
    if(a == 0)
        return a;

    b = a % 10;
    printf("%d", b);
    
    return inverter(a / 10);

}

void main(){
    int a;
    a = 625;
    inverter(a);

}