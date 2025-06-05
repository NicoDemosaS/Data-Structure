#ifndef PILHA_CONTIDA_H
#define PILHA_CONTIDA_H

int contida(pDPilha pilha1, pDPilha pilha2, FuncaoComparacao fc)
{

    pNoh l1 = pilha1->pdLista->primeiro;
    pNoh l2 = pilha2->pdLista->primeiro;

    while (l2 != NULL)
    {
        if (contemInfo(l1, l2->info, fc) != 0)
        {
            l2 = l2->prox;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

#endif
