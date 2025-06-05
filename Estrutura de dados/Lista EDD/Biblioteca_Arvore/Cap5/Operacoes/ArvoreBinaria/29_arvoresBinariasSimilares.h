#ifndef ARVORES_SIMILARES_H
#define ARVORES_SIMILARES_H
#include <stdio.h>

/* -------------------------------------------*/

// QUESTÃO 2

int similaresRecursiva(pNohArvore raiz1, pNohArvore raiz2)
{
    if (raiz1 == NULL && raiz2 == NULL)
    {
        return 0;
    }
    
    if (raiz1 == NULL && raiz2 != NULL)
    {
        return 1;
    }

    if (raiz1 != NULL && raiz2 == NULL)
    {
        return 1;
    }

    int direita = similaresRecursiva(raiz1->direita, raiz2->direita);
    int esquerda = similaresRecursiva(raiz1->esquerda, raiz2->esquerda);

    return direita + esquerda;
}

int similares(pDArvore arvore1, pDArvore arvore2)
{
    return similaresRecursiva(arvore1->raiz, arvore2->raiz);
}

#endif