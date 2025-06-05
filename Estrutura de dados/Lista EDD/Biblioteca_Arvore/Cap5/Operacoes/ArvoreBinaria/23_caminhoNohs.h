#ifndef CAMINHO_ENTRE_NOHS_H
#define CAMINHO_ENTRE_NOHS_H

int caminhoNohsRecursivo(pNohArvore raiz, void *info1, void *info2, FuncaoComparacao fc, int nivel, int val)
{
    if (raiz == NULL)
    {

        return nivel - 1;
    }

    if (fc(info1, raiz->info) == 0)
    {

        int val = 1;
        if (fc(info2, raiz->info) > 0)
        {

            nivel = nivel + 1;
            return caminhoNohsRecursivo(raiz->esquerda, info1, info2, fc, nivel, val);
        }
        if (fc(info2, raiz->info) < 0)
        {

            nivel = nivel + 1;
            return caminhoNohsRecursivo(raiz->direita, info1, info2, fc, nivel, val);
        }
    }

    if (val == 0)
    {
        if (fc(info1, raiz->info) > 0)
        {

            return caminhoNohsRecursivo(raiz->esquerda, info1, info2, fc, nivel, val);
        }
        if (fc(info1, raiz->info) < 0)
        {

            return caminhoNohsRecursivo(raiz->direita, info1, info2, fc, nivel, val);
        }
    }
    else
    {
        if (fc(info1, raiz->info) > 0)
        {

            nivel = nivel + 1;
            return caminhoNohsRecursivo(raiz->esquerda, info1, info2, fc, nivel, val);
        }
        if (fc(info1, raiz->info) < 0)
        {

            nivel = nivel + 1;
            return caminhoNohsRecursivo(raiz->direita, info1, info2, fc, nivel, val);
        }
    }

    if (val == 0)
    {
        if (fc(info2, raiz->info) > 0)
        {

            return caminhoNohsRecursivo(raiz->esquerda, info1, info2, fc, nivel, val);
        }
        if (fc(info2, raiz->info) < 0)
        {

            return caminhoNohsRecursivo(raiz->direita, info1, info2, fc, nivel, val);
        }
    }
    else
    {
        if (fc(info2, raiz->info) > 0)
        {

            nivel = nivel + 1;
            return caminhoNohsRecursivo(raiz->esquerda, info1, info2, fc, nivel, val);
        }
        if (fc(info2, raiz->info) < 0)
        {

            nivel = nivel + 1;
            return caminhoNohsRecursivo(raiz->direita, info1, info2, fc, nivel, val);
        }
    }

    if (fc(info2, raiz->info) == 0)
    {

        val = 0;
        return nivel;
    }

    return nivel;
}

//----------------------------------------------------------------------------------------------/

int caminhoNohs(pDArvore arv, void *info1, void *info2, FuncaoComparacao fc, int nivel, int val)
{
    return caminhoNohsRecursivo(arv->raiz, info1, info2, fc, nivel, val);
}

#endif