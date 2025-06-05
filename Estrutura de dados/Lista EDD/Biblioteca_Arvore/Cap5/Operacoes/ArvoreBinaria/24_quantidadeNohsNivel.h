#ifndef QUANTIDADE_NOHS_NIVEL_ARVORE_BINARIA_H
#define QUANTIDADE_NOHS_NIVEL_ARVORE_BINARIA_H
#include <stdio.h>

/* -------------------------------------------*/

int quantidadeNohsNivelRecursivo(pNohArvore raiz, int info, FuncaoComparacao fc, int nivel)
{

    if (raiz == NULL)
    {
        return 0;
    }

    int nohsEsquerda = 0;
    int nohsDireita = 0;

    if (nivel != info)
    {
        nohsEsquerda = quantidadeNohsNivelRecursivo(raiz->esquerda, info, fc, nivel + 1);
        nohsDireita = quantidadeNohsNivelRecursivo(raiz->direita, info, fc, nivel + 1);
    }

    if (nivel == info)
    {
        return 1;
    }

    return nohsEsquerda + nohsDireita;
}

int quantidadeNohsNivel(pDArvore arvore, int info, FuncaoComparacao fc)
{
    return quantidadeNohsNivelRecursivo(arvore->raiz, info, fc, 0);
}

#endif