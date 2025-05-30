#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "TAD_ListaLinear.h"
#include "Utils.h"


int main(){

    pDLista listaInt = criarLista();

    /* teste de inclusao */
    incluirInfoFim(listaInt, alocaInt(5));
    incluirInfoFim(listaInt, alocaInt(3));
    incluirInfoFim(listaInt, alocaInt(9));
    incluirInfoFim(listaInt, alocaInt(1));
    incluirInfoFim(listaInt, alocaInt(2));

    printf("\nResultado da inclusao \n");
    imprimirLista(listaInt, imprimeInt);

    int* nove = alocaInt(9);
    int* oito = alocaInt(8);

    //printf("\nResultado Exclusao\n");
    //excluirInfo(listaInt, nove, comparaInt);
    //imprimirLista(listaInt, imprimeInt);

    //printf("\nResultado Conter Info\n");
    //printf("[%d]\n", contemInfo(listaInt, oito, comparaInt));

    //printf("Teste Destruir Lista");
    //destruirLista(listaInt);
    //imprimirLista(listaInt, imprimeInt);

    printf("\nTeste Duplicacao Lista\n");
    pDLista listaInt2 = duplicarLista(listaInt, alocaInfoInt);
    imprimirLista(listaInt2, imprimeInt);

    pDLista outralista = dividirLista(listaInt, 3);
    printf("\nImprimindo outralista\n");
    imprimirLista(outralista, imprimeInt);
    printf("\nImprimindo listaint\n");
    imprimirLista(listaInt, imprimeInt);
    return 0;
}
