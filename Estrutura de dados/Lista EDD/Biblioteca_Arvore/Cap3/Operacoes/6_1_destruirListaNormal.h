#ifndef DESTRUIR_LISTA_NORMAL_H
#define DESTRUIR_LISTA_NORMAL_H


/* -------------------------------------*/
void destruirListaNormal(pDLista pd){

   pNoh atual, aux;
   atual = pd->primeiro;

   while (atual !=NULL){

      aux = atual->prox;
      free(atual);
      atual = aux;
   }

   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

#endif

