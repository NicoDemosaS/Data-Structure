
pNohArvore minValue(pDArvore arv)
{
    if (arv->raiz == NULL)
    {
        return NULL;
    }

    pNohArvore aux = arv->raiz;

    while (aux->esquerda != NULL)
    {
        aux = aux->esquerda;
    }

    return aux;
}


