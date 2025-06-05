#include <stdio.h>
#include "Utils.h"
#include "Fila.h"

int main(){

    pDFila filaInt = criarFila();

        /* teste de enfileiramento */
    enfileirarInfo(filaInt, alocaInt(5));
    enfileirarInfo(filaInt, alocaInt(3));
    enfileirarInfo(filaInt, alocaInt(2));
    enfileirarInfo(filaInt, alocaInt(7));
    enfileirarInfo(filaInt, alocaInt(2));

    /* teste de desenfileiramento */
    //void *info = desenfileirarInfo(filaInt);
    //printf("\nRetirou o inteiro = %d \n", *((int*)info));

    //while (filaVazia(filaInt)==0){
    //    info = desenfileirarInfo(filaInt);
    //    printf("\nRetirou o inteiro = %d \n", *((int*)info));
    //}

    printf("\nTestando maior info\n");
    void* maior = maiorInfo(filaInt, comparaInt);
    printf("%d", *((int*)maior));
}
