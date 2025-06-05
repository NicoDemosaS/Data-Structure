#ifndef CONTEM_VALOR_MAIOR_H
#define CONTEM_VALOR_MAIOR_H
#include <stdio.h>

/* -------------------------------------------*/

//QUESTÃO 4

int qtdeMaioresRecursiva(pNohArvore raiz, void *valor, FuncaoComparacao fc)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (fc(raiz->info, valor) < 0)
    {
        return qtdeMaioresRecursiva(raiz->esquerda, valor, fc) + qtdeMaioresRecursiva(raiz->direita, valor, fc) + 1;
    }
    int quantidadeEsquerda = qtdeMaioresRecursiva(raiz->esquerda, valor, fc);
    int quantidadeDireita = qtdeMaioresRecursiva(raiz->direita, valor, fc);
    return quantidadeDireita + quantidadeEsquerda;
}

int qtdeMaiores(pDArvore arvore, void *valor, FuncaoComparacao fc)
{
    return qtdeMaioresRecursiva(arvore->raiz, valor, fc);
}

#endif