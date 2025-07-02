#ifndef CONTIDA_LISTA_H
#define CONTIDA_LISTA_H
#include "../Utils.h"

int contida(pDLista lista1, pDLista lista2, FuncaoComparacao fc){
    pNoh atual;

    for(atual = lista2->inicio; atual != NULL; atual = atual->prox){
        if(contemInfo(lista1, atual->info, fc) == 0){
            return 0;
        }
    }
    return 1;
}



#endif