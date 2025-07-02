#ifndef COMPLEMENTO_LISTA_H
#define COMPLEMENTO_LISTA_H
#include "../Utils.h"

pDLista complemento(pDLista lista1, pDLista lista2, FuncaoComparacao fc){
    pDLista novalista = criarLista();
    pNoh atual;
    for(atual = lista2->inicio; atual != NULL ; atual = atual->prox){
        if(contemInfo(lista1, atual->info, comparaInt) == 0)
            incluirInfoFim(novalista, atual->info);
    }

    return novalista;

}



#endif