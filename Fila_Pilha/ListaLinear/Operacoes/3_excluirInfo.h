#ifndef EXCLUIR_INFO_H
#define EXCLUIR_INFO_H

int excluirInfo(pDLista pd, void *info, FuncaoComparacao pfc){
    pNoh atual;
    pNoh anterior;
    atual = pd->inicio;
    anterior = NULL;
    while(atual!=NULL){
        if(pfc(atual->info, info) == 0){
            // EXCLUIR
            if(anterior==NULL){
                pd->inicio = atual->prox;
            }
            else{
                anterior->prox = atual->prox;
            }
            free(atual);
            pd->quantidade--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;

    }
    return 0;
}

int excluirInfoTotal(pDLista pd, void *info, FuncaoComparacao pfc, FuncaoLiberacao pl){
        pNoh atual;
    pNoh anterior;
    atual = pd->inicio;
    anterior = NULL;
    while(atual!=NULL){
        if(pfc(atual->info, info) == 0){
            // EXCLUIR
            if(anterior==NULL){
                pd->inicio = atual->prox;
            }
            else{
                anterior->prox = atual->prox;
            }
            pl(atual);
            pd->quantidade--;
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void* excluirInfoPos(pDLista pd, int pos){

    int cont=1;

    pNoh atual, ant;

    atual = pd->inicio;
    ant   = NULL;

    /* encontra o noh correspondente a posicao informada */
    while(atual != NULL && cont < pos){
       ant   = atual;
       atual = atual->prox;
       cont++;
    }

    /* verifica se a info existe na lista */
    if (atual != NULL){
        /* eh o inicio da lista */
        if (atual == pd->inicio)
            pd->inicio = atual->prox;
        else
        /* eh o fim da lista */
        if (atual == pd->fim){
            pd->fim = ant;
            ant->prox  = NULL;
        } else
             /* estah no meio da lista */
             ant->prox = atual->prox;

        pd->quantidade--;
        void * auxInfo = atual->info;
        free(atual);
        return auxInfo;
    }

    return NULL;
}

#endif
