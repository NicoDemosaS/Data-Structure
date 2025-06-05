#ifndef TROCA_FILA_H
#define TROCA_FILA_H

void troca(pDFila fila, void *a, void *b, FuncaoComparacao pfc)
{
    // pNoh aux = fila->pdLista->primeiro;

    int pos1 = contemInfo(fila->pdLista, a, pfc);
    int pos2 = contemInfo(fila->pdLista, b, pfc);

    incluirInfoMeio(fila->pdLista, b, pos1);
    incluirInfoMeio(fila->pdLista, a, pos2);

    excluirInfoPos(fila->pdLista, pos1 + 2);
    excluirInfoPos(fila->pdLista, pos2 + 1);
}

#endif