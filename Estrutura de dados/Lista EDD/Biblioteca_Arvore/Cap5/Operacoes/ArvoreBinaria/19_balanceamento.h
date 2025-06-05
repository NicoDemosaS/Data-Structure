#ifndef BALANCEAMENTO_H
#define BALANCEAMENTO_H

int balanceadaRecursiva(pNohArvore raiz)
{
    int auxEsquerda = alturaArvoreRecursiva(raiz->esquerda);
    int auxDireita = alturaArvoreRecursiva(raiz->direita);

    int altura = auxDireita-auxEsquerda;

    if (altura == 1 || altura == 0 || altura == -1)
    {
        return 1;
    } else
    {
        return 0;
    }
}

int balanceada(pDArvore arv)
{
    return balanceadaRecursiva(arv->raiz);
}

#endif
