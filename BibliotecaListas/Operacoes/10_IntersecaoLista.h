#ifndef INTERSECAO_LISTA_H
#define INTERSECAO_LISTA_H
#include "../Utils.h"


pDLista intersecaoListas(pDLista lista1, pDLista lista2, FuncaoComparacao fc){
    pNoh atual;
    pDLista novalista = malloc(sizeof(struct dLista));

    for(atual = lista2->inicio; atual != NULL; atual = atual->prox){
        if(contemInfo(lista1, atual->info, fc) == 1){
            incluirInfoFim(novalista, alocaInfoInt(atual->info));
            lista1->quantidade++;
        }
    }
    
    return novalista;
}



#endif