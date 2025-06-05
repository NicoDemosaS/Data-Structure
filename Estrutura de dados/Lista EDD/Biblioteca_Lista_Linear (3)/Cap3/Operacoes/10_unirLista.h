#ifndef UNIR_LISTA_H
#define UNIR_LISTA_H


pDLista unirLista(pDLista lista1, pDLista lista2, FuncaoComparacao pfc)
{
   pDLista novaLista = criarLista();

   pNoh l1 = lista1->primeiro;
   pNoh l2 = lista2->primeiro;
   while (l1 != NULL)
   {
      if (contemInfo(novaLista, l1->info, pfc) == 0)
      {
         incluirInfo(novaLista, l1->info);
      }

      l1 = l1->prox;
   }
   while (l2 != NULL)
   {
      if (contemInfo(novaLista, l2->info, pfc) == 0)
      {
         incluirInfo(novaLista, l2->info);
      }
      l2 = l2->prox;
   }
   return novaLista;
}

#endif
