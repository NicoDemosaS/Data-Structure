#ifndef ARVORE_IGUAL_H
#define ARVORE_IGUAL_H

int arvoreIgualRecursivo(pNohArvore raiz1, pNohArvore raiz2, FuncaoComparacao fc)
{
    if (raiz1 == NULL && raiz2 == NULL)
    {
        printf("1");
        return 1;
    }

    if (raiz1 == NULL || raiz2 == NULL)
    {
        printf("2");
        return 0;
    }

    if (fc(raiz1->info, raiz2->info) == 1)
    {
        printf("3");
        return 0;
    }

    int igualEsquerda = arvoreIgualRecursivo(raiz1->esquerda, raiz2->esquerda, fc);
    int igualDireita = arvoreIgualRecursivo(raiz1->direita, raiz2->direita, fc);

    return igualEsquerda && igualDireita;
}

/*----------------------------------------------------------------------------------------------*/

int arvoreIgual(pDArvore arv1, pDArvore arv2, FuncaoComparacao fc)
{
    return arvoreIgualRecursivo(arv1->raiz, arv2->raiz, fc);
}
#endif
