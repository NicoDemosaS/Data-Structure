#ifndef IMPRIMIR_LISTA_H
#define IMPRIMIR_LISTA_H

void imprimirLista(pDLista pd, FuncaoImpressao pfi)
{

    pNoh aux;
    aux = pd->primeiro;

    while (aux != NULL)
    {
        /*printf("%d", *(((int *)aux->info)));*/
        pfi(aux->info);

        aux = aux->prox;
    }
}

void imprimirListaRecursiva(pNoh atual, FuncaoImpressao pfi)
{
    if (atual == NULL)
    {
        return;
    }
    else
    {
        pfi(atual->info);
        imprimirListaRecursiva(atual->prox, pfi);
    }
}

#endif
