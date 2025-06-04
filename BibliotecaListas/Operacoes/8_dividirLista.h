#ifndef DIVIDIR_LISTA_H
#define DIVIDIR_LISTA_H


pDLista dividirLista(pDLista pListaOriginal, int pos)
{
    pNoh atual = pListaOriginal->inicio;
    pDLista novalista = malloc(sizeof(DLista));
    novalista->inicio = NULL;
    int i;
    for(i=0;i<pos - 1 && atual->prox != NULL; i++){
        atual = atual->prox;
    }
    if (atual == NULL || atual->prox == NULL)
        return NULL; // posição inválida
    
    novalista->inicio = atual->prox;
    atual->prox = NULL;

    novalista->quantidade = pListaOriginal->quantidade - pos;
    pListaOriginal->quantidade -= pos;

    novalista->fim = pListaOriginal->fim;
    pListaOriginal->fim = atual;
    
    return novalista;
}

#endif
