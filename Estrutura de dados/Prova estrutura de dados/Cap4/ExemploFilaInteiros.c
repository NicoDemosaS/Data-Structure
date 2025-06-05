#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Fila.h"

int main()
{
    pDFila pFilaInt = criarFila();

    /* teste de enfileiramento */
    enfileirarInfo(pFilaInt, alocaInt(5));
    enfileirarInfo(pFilaInt, alocaInt(3));
    enfileirarInfo(pFilaInt, alocaInt(9));
    enfileirarInfo(pFilaInt, alocaInt(1));
    enfileirarInfo(pFilaInt, alocaInt(2));

    // inverter a fila
    pDFila filaInvertida = inverteFila(pFilaInt);
    printf("\nFila invertida\n");
    imprimirLista(filaInvertida->pdLista, imprimeInt);

    // duplicar a lista
    pDFila filaCopiada = copia(pFilaInt, alocaInfoInt);
    printf("\nFila duplicada\n");
    imprimirLista(pFilaInt->pdLista, imprimeInt);
    printf("\n");
    imprimirLista(filaCopiada->pdLista, imprimeInt);

    //trocar infos
    troca(pFilaInt, alocaInt(1), alocaInt(3), comparaInt);
    printf("\ntrocar duas infos\n");
    imprimirLista(pFilaInt->pdLista,imprimeInt);


    /* teste de desenfileiramento */
    void *info = desenfileirarInfo(pFilaInt);
    printf("\n\nRetirou o inteiro = %d \n", *((int *)info));

    while (filaVazia(pFilaInt) == 0)
    {
        info = desenfileirarInfo(pFilaInt);
        printf("\nRetirou o inteiro = %d \n", *((int *)info));
    }
}
