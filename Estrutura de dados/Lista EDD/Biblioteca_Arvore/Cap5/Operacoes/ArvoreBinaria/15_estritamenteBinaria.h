#ifndef ESTRITAMENTE_BINARIA_H
#define ESTRITAMENTE_BINARIA_H

int estritamenteBinariaRecursiva(pNohArvore raiz)
{
    if (raiz->direita == NULL && raiz->esquerda==NULL)
    {
        printf("1");
        return 1;
    }

    if (raiz->esquerda != NULL && raiz->direita != NULL)
    {
        printf("2");
        int binarioEsquerda = estritamenteBinariaRecursiva(raiz->esquerda);
        int binarioDireita = estritamenteBinariaRecursiva(raiz->direita);
        return binarioDireita && binarioEsquerda;
    }

    if (raiz->esquerda == NULL || raiz->direita == NULL)
    {
        printf("3");
        return 0;
    }
    return 0;
}
/*----------------------------------------------------------------------------------------------*/

int estritamenteBinaria(pDArvore arv)
{
    return estritamenteBinariaRecursiva(arv->raiz);
}

#endif
