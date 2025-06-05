#ifndef DISJUNCAO_LISTA_H
#define DISJUNCAO_LISTA_H
#include "../Utils.h"

int disjuncaoListas(pDLista lista1, pDLista lista2, FuncaoComparacao fc){
    pNoh atual;
    pDLista novalista = malloc(sizeof(struct dLista));

    for(atual = lista2->inicio; atual != NULL; atual = atual->prox){
        if(contemInfo(lista1, atual->info, fc) == 1){
            return 0;
        }
    return 1;
    
    }
}

#endif