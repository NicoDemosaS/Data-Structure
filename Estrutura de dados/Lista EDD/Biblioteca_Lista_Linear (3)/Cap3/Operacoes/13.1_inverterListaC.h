#ifndef INVERTER_LISTA_C_H
#define INVERTER_LISTA_C_H

pDLista inverterListaC(pDLista lista)
{
    pDLista pNovaLista = criarLista();
    pNoh atual = lista->primeiro;

    while (atual != NULL)
    {
        incluirInfoInicio(pNovaLista, atual->info);
        atual = atual->prox;
    }

    return pNovaLista;
}

#endif