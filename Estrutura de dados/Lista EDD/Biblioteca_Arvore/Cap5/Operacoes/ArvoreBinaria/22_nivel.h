#ifndef NIVEL_ARVORE_H
#define NIVEL_ARVORE_H

int nivelRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc, int nivel)
{
    if (raiz == NULL)
    {

        return 0;
    }

    if (fc(raiz->info, info) == 0)
    {

        return nivel;
    }

    if (raiz->direita == NULL && raiz->esquerda == NULL)
    {

        return 0;
    }

    if (raiz->direita == NULL && raiz->esquerda != NULL)
    {
        nivel = nivel + 1;
        return nivelRecursivo(raiz->esquerda, info, fc, nivel);
    }

    if (raiz->direita != NULL && raiz->esquerda == NULL)
    {
        nivel = nivel + 1;
        return nivelRecursivo(raiz->direita, info, fc, nivel);
    }

    nivel = nivel + 1;
    int nivelEsquerda = nivelRecursivo(raiz->esquerda, info, fc, nivel);
    int nivelDireita = nivelRecursivo(raiz->direita, info, fc, nivel);

    if (nivelEsquerda != 0 || nivelDireita != 0)
    {

        return nivelEsquerda > nivelDireita ? nivelEsquerda : nivelDireita;
    }

    return 0;
}

/*----------------------------------------------------------------------------------------------*/

int nivel(pDArvore arv, void *info, FuncaoComparacao fc, int nivel)
{
    return nivelRecursivo(arv->raiz, info, fc, nivel);
}

#endif
