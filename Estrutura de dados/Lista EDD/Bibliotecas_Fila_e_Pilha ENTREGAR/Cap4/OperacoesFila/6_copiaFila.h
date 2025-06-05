#ifndef COPIA_FILA_H
#define COPIA_FILA_H

pDFila copia(pDFila fila, FuncaoAlocacao fa)
{

    pDFila copiaFila = criarFila();


    pNoh aux = fila->pdLista->primeiro;
    while(aux!=NULL)
    {
        //aloca memoria e copia do valor do campo info
        void *info = fa(aux->info);
        //adiciona a copia da informação na nova lista
        incluirInfo(copiaFila->pdLista, info);

        aux = aux->prox;
    }
    return copiaFila;
}

#endif
