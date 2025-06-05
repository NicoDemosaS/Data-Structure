#ifndef INCLUIR_INFO_MEIO_BASE_H
#define INCLUIR_INFO_MEIO_BASE_H

//PROVA PROVA PROVA PROVA PROVA 
// A lógica foi feita, mas não sei porque o erro Permission denied persiste
int incluirInfoBase(pDLista lista, void *info, void *infoBase, FuncaoComparacao fc)
{
    pNoh l1 = lista->primeiro;
    while (l1 != NULL)
    {
        if (fc(l1->info, infoBase) == 0)
        {
            int pos = contemInfo(lista, infoBase, fc);
            incluirInfoMeio(lista, info, pos);
            return 1;
        }
        l1=l1->prox;
    }
   return 0;
}

#endif