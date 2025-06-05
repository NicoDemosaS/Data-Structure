

pNohArvore maxValue(pDArvore arv)
{
    if (arv->raiz == NULL)
    {
        return NULL;
    }

    pNohArvore aux = arv->raiz;

    while (aux->direita != NULL)
    {
        aux = aux->direita;
    }

    return aux;
}


