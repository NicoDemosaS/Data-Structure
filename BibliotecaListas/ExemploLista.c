#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "TAD_ListaLinear.h"
#include "Utils.h"


int main(){

    pDLista listaInt = criarLista();


    int* nove = alocaInt(9);
    /* teste de inclusao */
    incluirInfoFim(listaInt, alocaInt(5));
    incluirInfoFim(listaInt, alocaInt(3));
    incluirInfoFim(listaInt, nove);
    incluirInfoFim(listaInt, alocaInt(1));
    incluirInfoFim(listaInt, alocaInt(2));
    incluirInfoFim(listaInt, alocaInt(12));
    incluirInfoFim(listaInt, alocaInt(13));

    printf("\nResultado da inclusao \n");
    imprimirLista(listaInt, imprimeInt);

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

    pDLista listaInt3 = criarLista();

    incluirInfoFim(listaInt3, alocaInt(12));

    incluirInfoFim(listaInt3, alocaInt(15));

    incluirInfoFim(listaInt3, alocaInt(19));

    //pDLista outralista = dividirLista(listaInt, 3);
    //printf("\nImprimindo outralista\n");
    //imprimirLista(outralista, imprimeInt);
    //printf("\nImprimindo listaint\n");
    //imprimirLista(listaInt, imprimeInt);
    
    //printf("\nTestando incluir Inicio\n");
    //incluirInfoInicio(listaInt, nove);
    //incluirInfoInicio(listaInt, oito);
    //imprimirLista(listaInt, imprimeInt);


    

    //printf("\nTestando excluir total\n");
    //imprimirLista(listaInt, imprimeInt);
    //excluirInfoTotal(listaInt, nove, comparaInt, LiberaNoh);
    //printf("\n");
    //imprimirLista(listaInt, imprimeInt);
    //printf("\n[%d]", *nove);


    //UNIR listas
    

    //Intersecao
    printf("\nIntersecao Nova lista \n");
    pDLista novalista = intersecaoListas(listaInt, listaInt3, comparaInt);
    imprimirLista(novalista, imprimeInt);


    //Disjuncao
    printf("\nDisjuncao \n");
    printf("%d", disjuncaoListas(listaInt, listaInt3, comparaInt));




    return 0;
}
