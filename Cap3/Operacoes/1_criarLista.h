#ifndef CRIAR_LISTA_H
#define CRIAR_LISTA_H

pDLista criarLista(){

   pDLista lista = malloc(sizeof(DLista));

   lista->inicio = NULL;
   lista->fim    = NULL;
   lista->quantidade = 0;

   return lista;
}

#endif
