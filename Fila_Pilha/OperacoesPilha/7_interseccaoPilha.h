#ifndef BALANCEAMENTO_PILHA_H
#define BALANCEAMENTO_PILHA_H
#include <stdio.h>

pDPilha interseccao(pDPilha pilha1, pDPilha pilha2, FuncaoComparacao fc)
{
    pDPilha novaPilha = criarPilha();

    pNoh l1 = pilha1->pdLista->primeiro;
    pNoh l2 = pilha2->pdLista->primeiro;

    while (l1 != NULL)
    {
        if ((contemInfo(pilha2->pdLista, l1->info, fc) != 0) && (contemInfo(novaPilha->pdLista, l1->info, fc) == 0))
        {
            incluirInfo(novaPilha->pdLista, l1->info);
        }

        l1 = l1->prox;
    }

    return novaPilha;
}




#endif