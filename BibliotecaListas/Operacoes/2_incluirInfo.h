#ifndef INCLUIR_INFO_FIM_H
#define INCLUIR_INFO_FIM_H

void incluirInfoFim(pDLista pd, void *info){

      pNoh novo = (pNoh)malloc(sizeof(Noh));
      novo->info = info;
      novo->prox = NULL;
      if(pd->inicio == NULL)
         pd->inicio = novo;

      if (pd->fim != NULL)
          pd->fim->prox = novo;

      pd->fim = novo;
}

void incluirInfoMeio(pDLista pd, void *info, int posicao){
    int i = 0;
    pNoh atual;
    pNoh anterior = pd->inicio;
    pNoh novo = (pNoh)malloc(sizeof(struct noh));
    atual = pd->inicio;
    for(i = 0; i < posicao; i++){
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novo;
    novo->info = info;
    novo->prox = atual;
}

void incluirInfoInicio(pDLista pd, void *info){
    pNoh atual = pd->inicio;
    pNoh novo = malloc(sizeof(struct noh));

    if(pd->inicio == NULL){
        pd->inicio = novo;
        pd->fim = novo;
        novo->info = info;
    }
    else{
        pd->inicio = novo;
        novo->prox = atual;
        novo->info = info;
    }
    pd->quantidade++;
}

#endif
