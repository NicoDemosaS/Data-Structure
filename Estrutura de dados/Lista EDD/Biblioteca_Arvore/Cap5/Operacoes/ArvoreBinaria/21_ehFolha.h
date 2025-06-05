#ifndef CONFIRMA_FOLHA_H
#define CONFIRMA_FOLHA_H

int ehFolhaRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (fc(raiz->info, info) == 0)
    {

        if (raiz->esquerda == NULL && raiz->direita == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int folhaEsquerada = ehFolhaRecursivo(raiz->esquerda, info, fc);
    int folhaDireita = ehFolhaRecursivo(raiz->direita, info, fc);

    if (folhaDireita == 1 || folhaEsquerada == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*----------------------------------------------------------------------------------------------*/

int ehFolha(pDArvore arv, void *info, FuncaoComparacao fc)
{
    return ehFolhaRecursivo(arv->raiz, info, fc);
}

#endif
