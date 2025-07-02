#ifndef INVERTER_LISTA_H
#define INVERTER_LISTA_H
#include "../Utils.h"

void inverterLista(pDLista lista){
   
    pNoh anterior = NULL;
    pNoh atual = lista->inicio;
    pNoh proximo = NULL;


    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->fim = lista->inicio;
    lista->inicio = anterior; 
}

pDLista inverterListaComRetorno(pDLista lista){
    
    pDLista listaInvertida = duplicarLista(lista, alocaInfoInt);

    pNoh anterior = NULL;
    pNoh atual = listaInvertida->inicio;
    pNoh proximo = NULL;


    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    listaInvertida->fim = lista->inicio;
    listaInvertida->inicio = anterior; 

    return listaInvertida;
}




#endif