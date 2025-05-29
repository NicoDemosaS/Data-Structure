#ifndef DUPLICAR_LISTA_H
#define DUPLICAR_LISTA_H


pDLista duplicarLista(pDLista pd, FuncaoAlocacao fa)
{
    pNoh atual = pd->inicio;
    pDLista novalista = malloc(sizeof(DLista));
    novalista->inicio = NULL;
    while(atual!= NULL){
        incluirInfoFim(novalista, fa(atual->info));
        atual = atual->prox;
        novalista->quantidade++;
    }
    novalista->fim = atual;
    return novalista;
}

#endif
