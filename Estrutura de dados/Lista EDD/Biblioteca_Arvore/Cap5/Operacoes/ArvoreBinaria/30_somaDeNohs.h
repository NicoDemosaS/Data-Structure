#ifndef SOMA_NOH_MAPEADO_H
#define SOMA_NOH_MAPEADO_H
#include <stdio.h>

/* -------------------------------------------*/

// QUESTÃO 1

int somaNohMapeadoRecursivo (pNohArvore raiz, FuncaoMapeamento fm)
{
    if (raiz == NULL)
    {
        return 0;
    }

    int somaEsquerda = somaNohMapeadoRecursivo(raiz->esquerda, fm);
    int somaDireita = somaNohMapeadoRecursivo(raiz->direita, fm);

    return fm(raiz->info) + somaEsquerda + somaDireita;

}

int somaNohMapeado (pDArvore arvore, FuncaoMapeamento fm)
{
    return somaNohMapeadoRecursivo(arvore->raiz, fm);
}

#endif