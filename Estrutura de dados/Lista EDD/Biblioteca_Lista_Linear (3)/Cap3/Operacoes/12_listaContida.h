#ifndef CONTIDA_LISTA_H
#define CONTIDA_LISTA_H

int contida(pDLista lista1, pDLista lista2, FuncaoComparacao fc)
{


pNoh l1 = lista1->primeiro;
pNoh l2 = lista2->primeiro;

while (l2!=NULL)
{
    if(contemInfo(lista1, l2->info,fc)!=0)
    {
        l2=l2->prox;
    } else {
        return 1;
    }

}
return 0;

}

#endif