#ifndef UNIR_LISTA_H
#define UNIR_LISTA_H
#include "../Utils.h"

pDLista unirListas(pDLista lista1, pDLista lista2, FuncaoComparacao fc){

    pNoh atual2 = lista2->inicio;

    for(atual2 = lista2->inicio; atual2 != NULL; atual2 = atual2->prox){
        if(contemInfo(lista1, atual2->info, fc) == 0){
            incluirInfoFim(lista1, alocaInfoInt(atual2->info));
            lista1->quantidade++;
        }
    }
    
    return lista1;
}





















#endif
