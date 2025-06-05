#ifndef SOMENTE_UM_FILHO_H
#define SOMENTE_UM_FILHO_H
#include <stdio.h>

/* -------------------------------------------*/

//QUESTÃO 3

int SomenteUmFilhoRecursivo(pNohArvore raiz)
{
    if (raiz == NULL)
        return 0;

    if (raiz->esquerda != NULL && raiz->direita == NULL)
        return 1;

    if (raiz->esquerda == NULL && raiz->direita != NULL)
        return 1; /*  � uma folha */

    return quantidadeFolhasRecursiva(raiz->esquerda) +
           quantidadeFolhasRecursiva(raiz->direita);
}

int SomenteUmFilho(pDArvore arvore)
{
    return SomenteUmFilhoRecursivo(arvore->raiz);
}

#endif