#ifndef ARVORE_BUSCA_BINARIA_H
#define ARVORE_BUSCA_BINARIA_H


int isBSTrecursiva (pNohArvore raiz, void *min, void *max)
{
    if (raiz == NULL)
    {
        return 1;
    }

    pNohArvore minNoh = (pNohArvore)min;
    pNohArvore maxNoh = (pNohArvore)max;

    if (raiz->esquerda > maxNoh && raiz->direita < minNoh)
    {
        return 0;
    }

    if (raiz->esquerda < maxNoh && raiz->direita > minNoh)
    {
        isBSTrecursiva(raiz->esquerda, min, raiz);
        isBSTrecursiva(raiz->direita, raiz, max);
    }

    return 1;
}

int isBST(pDArvore arv, void *min, void *max)
{
    return isBSTrecursiva(arv->raiz, min, max);
}


#endif