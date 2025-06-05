#ifndef UNIR_LISTA_COMUM_H
#define UNIR_LISTA_COMUM_H

pDLista unirListaComum(pDLista lista1, pDLista lista2, FuncaoComparacao pfc)
{
   pDLista novaLista = criarLista();

   pNoh l1 = lista1->primeiro;
   pNoh l2 = lista2->primeiro;

   while (l1 != NULL)
   {
      if ((contemInfo(lista2, l1->info, pfc) != 0) && (contemInfo(novaLista, l1->info, pfc) == 0))
      {
         incluirInfo(novaLista, l1->info);
      }

      l1 = l1->prox;
   }

   return novaLista;
}

#endif
