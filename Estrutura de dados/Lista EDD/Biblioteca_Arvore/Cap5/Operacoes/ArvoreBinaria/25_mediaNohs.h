#ifndef MEDIA_NOHS_ARVORE_BINARIA_H
#define MEDIA_NOHS_ARVORE_BINARIA_H
#include <stdio.h>

int somaNohsRecursiva(pNohArvore raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    int somaEsquerda = somaNohsRecursiva(raiz->esquerda);
    int somaDireita = somaNohsRecursiva(raiz->direita);

    void *infoV = raiz->info;
    int *infoInt = (int *)infoV;

    return *infoInt + somaEsquerda + somaDireita;
}


float mediaNohs(pDArvore arvore)
{
    int quantidadeNohs = quantidadeNohsRecursiva(arvore->raiz);
    int somaTotal = somaNohsRecursiva(arvore->raiz);

    if (quantidadeNohs != 0)
    {
        return somaTotal / (float)quantidadeNohs;
    }
    else
    {
        return 0;
    }
}


#endif