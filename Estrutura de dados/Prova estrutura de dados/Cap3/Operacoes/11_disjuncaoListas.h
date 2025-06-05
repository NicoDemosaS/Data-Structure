#ifndef DISJUNCAO_LISTA_H
#define DISJUNCAO_LISTA_H

int disjuncaoListas(pDLista lista1, pDLista lista2, FuncaoComparacao pfc)
{

    pNoh l1 = lista1->primeiro;
    pNoh l2 = lista2->primeiro;
    int aux;
    while (l2!=NULL)
    {
        if (contemInfo(lista1, l2->info, pfc) == 0)
        {   
            l2=l2->prox;
        } 
        else
        {
            return 0;
        }
        
    }
    return 1;
}

#endif