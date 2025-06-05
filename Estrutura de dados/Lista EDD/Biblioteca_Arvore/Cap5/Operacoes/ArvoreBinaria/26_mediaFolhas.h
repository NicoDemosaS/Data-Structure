#ifndef MEDIA_FOLHAS_ARVORE_BINARIA_H
#define MEDIA_FOLHAS_ARVORE_BINARIA_H
#include <stdio.h>

int somaFolhasRecursiva(pNohArvore raiz)
{
    if (raiz == NULL)
        return 0;

    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {

        void *infoV = raiz->info;
        int *infoInt = (int *)infoV;

        return *infoInt;
    }

    int folhasEsquerda = somaFolhasRecursiva(raiz->esquerda);
    int folhasDireita = somaFolhasRecursiva(raiz->direita);

    return folhasEsquerda + folhasDireita;
}

float mediaFolhas(pDArvore arvore)
{
    int quantidadefolhas = quantidadeFolhasRecursiva(arvore->raiz);
    int somaTotal = somaFolhasRecursiva(arvore->raiz);

    if (quantidadeNohs != 0)
    {
        return somaTotal / (float)quantidadefolhas;
    }
    else
    {
        return 0;
    }
}

#endif