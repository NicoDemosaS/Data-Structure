#ifndef PILHA_IGUAL_H
#define PILHA_IGUAL_H

int Iguais(pDPilha pilha1, pDPilha pilha2, FuncaoComparacao fc)
{

    pNoh l1 = pilha1->pdLista->primeiro;
    pNoh l2 = pilha2->pdLista->primeiro;

  
    while (l2 != NULL)
    {
        if (contemInfo(pilha1->pdLista, l2->info, fc) == 0)
        {
            return 0;
        }
        if (contemInfo(pilha1->pdLista, l2->info, fc) != 0)
        {
            l2 = l2->prox;
        }
        
    }
    return 1;
}

#endif