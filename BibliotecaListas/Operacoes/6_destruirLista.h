#ifndef DESTRUIR_LISTA_H
#define DESTRUIR_LISTA_H

/* -------------------------------------*/
void destruirLista(pDLista pd){
    pNoh atual = pd->inicio;
    pNoh anterior = atual;
    while(anterior != NULL){
        anterior = atual;
        atual = atual->prox;
        free(anterior);
    }
}

#endif

