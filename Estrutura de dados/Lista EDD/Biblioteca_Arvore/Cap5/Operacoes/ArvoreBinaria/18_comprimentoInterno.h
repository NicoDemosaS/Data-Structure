#ifndef COMPRIMENTO_INTERNO_H
#define COMPRIMENTO_INTERNO_H
#include <stdio.h>

int comprimentoInternoRecursivo(pNohArvore raiz, int compr)
{

    if (raiz == NULL)
    {
        return compr - 1;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        return compr;
    }

    if (raiz->esquerda == NULL && raiz->direita != NULL)
    {
        return comprimentoInternoRecursivo(raiz->direita, compr + 1);
    }

    if (raiz->esquerda != NULL && raiz->direita == NULL)
    {
        return comprimentoInternoRecursivo(raiz->esquerda, compr + 1);
    }

    return comprimentoInternoRecursivo(raiz->esquerda, compr + 1) + comprimentoInternoRecursivo(raiz->direita, compr + 1);
}
/*
    printf("\n\nraiz=");
        if (raiz != NULL) {
             imprimeInt(raiz->info);
        }

if (raiz == NULL)
{
    printf("\n1\n");
    return 0;
}

if (raiz->esquerda == NULL && raiz->direita == NULL)
{
    printf("\n2\n");
    return 0;
}

if (raiz->esquerda != NULL || raiz->direita != NULL)
{

    if(raiz->esquerda == NULL && raiz ->direita != NULL)
    {
        return comprimentoInternoRecursivo(raiz->direita) + 1;
    }

    if (raiz->direita == NULL && raiz-> esquerda != NULL)
    {
        return comprimentoInternoRecursivo(raiz->esquerda) + 1;
    }
    printf("\n3\n");

    int raizEsquerda = comprimentoInternoRecursivo(raiz->esquerda) + 1;
    int raizDireita = comprimentoInternoRecursivo(raiz->direita) + 1;
    printf("\nvalor raiz Esquerda: %d\n",raizEsquerda);
    printf("\nvalor raiz Direita: %d\n",raizDireita);
    return raizDireita + raizEsquerda;
}
*/

/*----------------------------------------------------------------------------------------------*/

int comprimentoInterno(pDArvore arv)
{
    return comprimentoInternoRecursivo(arv->raiz, 0);
}

#endif
