#ifndef COPIA_PILHA_H
#define COPIA_PILHA_H

pDPilha copiaPilha(pDPilha pilha, FuncaoAlocacao fa)
{

   pDPilha copiaPilha = criarPilha();

    pNoh aux = pilha->pdLista->primeiro;
    while (aux != NULL)
    {
        // aloca memoria e copia do valor do campo info
        void *info = fa(aux->info);
        // adiciona a copia da informação na nova lista
        incluirInfo(copiaPilha->pdLista, info);

        aux = aux->prox;
    }
    return copiaPilha;
}

#endif
