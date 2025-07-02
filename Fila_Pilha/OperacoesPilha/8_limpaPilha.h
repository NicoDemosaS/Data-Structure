#ifndef LIMPA_PILHA_H
#define LIMPA_PILHA_H

void limpaPilha(pDPilha pilha)
{
    if (pilhaVazia(pilha) == 1)
    {
        return;
    }
    else
    {
        desempilharInfo(pilha);
        limpaPilha(pilha);
    }
}
#endif
