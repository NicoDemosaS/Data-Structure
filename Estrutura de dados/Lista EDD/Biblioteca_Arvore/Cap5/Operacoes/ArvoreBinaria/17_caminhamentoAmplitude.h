#ifndef CAMINHAMENTO_AMPLITUDE_H
#define CAMINHAMENTO_AMPLITUDE_H

void amplitude(pDArvore arv, FuncaoImpressao fi, FuncaoComparacao fc)
{
        if (arv->raiz == NULL)
    {
        return;
    }

    pDLista listaAmplitude = criarLista();

    incluirInfoLista(listaAmplitude, arv->raiz);

    while (buscarInfoPos(listaAmplitude, 1) != NULL)
    {
        pNohArvore noh = excluirInfoPos(listaAmplitude, 1);

        fi(noh->info); // Imprime o valor do nó usando a função de impressão fornecida

        incluirInfoLista(listaAmplitude, noh->esquerda);
        incluirInfoLista(listaAmplitude, noh->direita);
    }
}


#endif
