#ifndef INVERTER_LISTA_H
#define INVERTER_LISTA_H

pDLista inverterLista(pDLista lista)
{
    pNoh ant;
    pNoh atual;
    pNoh auxPrimeiro;
    auxPrimeiro = lista->primeiro;
    lista->primeiro = lista->ultimo;
    lista->ultimo = auxPrimeiro;
    atual = auxPrimeiro->prox;
    ant = auxPrimeiro;

    while (atual != NULL)
    {
        auxPrimeiro = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = auxPrimeiro;
    }
    lista->ultimo->prox = NULL;
    return lista;
}
#endif
/*
pNoh auxPrimeiro;
    pNoh atual;
    pNoh ant;

    auxPrimeiro = lista->primeiro;
    lista->primeiro = lista->ultimo;
    lista->ultimo = auxPrimeiro;
    atual = auxPrimeiro->prox;
    ant = auxPrimeiro;

    while(atual != NULL)
    {
        auxPrimeiro = atual->prox;
        atual->prox = ant;
        ant=atual;
        atual=auxPrimeiro;

    }
    lista->ultimo->prox=NULL;
    return lista;
*/