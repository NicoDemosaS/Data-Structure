#ifndef DIVIDIR_LISTA_INFO_H
#define DIVIDIR_LISTA_INFO_H

pDLista dividirListaInfo(pDLista pListaOriginal, void *info, FuncaoComparacao pfc)
{
    
    //Cria uma nova lista para guardar parte dos Nohs da lista original
    pDLista pNovaLista = criarLista();

    //Percorre a lista original para encontrar a posição onde deve dividir a lista
    pNoh atual = pListaOriginal->primeiro;

    int contador = 1;

    //a 
    while (pfc(atual->info, info) != 0 && atual != NULL)
    {
        atual = atual->prox;
        contador++;
    }

    if (atual != NULL)
    {
        //atualiza o descritor da lista nova
        pNovaLista->primeiro = atual->prox;
        pNovaLista->ultimo     = pListaOriginal->ultimo;
        pNovaLista->quantidade = pListaOriginal->quantidade - contador;

         /* atualiza o descritor da lista original */
        pListaOriginal->ultimo = atual;
        pListaOriginal->quantidade = pListaOriginal->quantidade - pNovaLista->quantidade;
        /* finaliza a lista original */
        atual->prox = NULL;
    }
    return pNovaLista;
}
#endif //DIVIDIR_LISTA_INFO_H