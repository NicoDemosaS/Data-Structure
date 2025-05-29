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
            return 1;
        }
        anterior = atual;
        atual = atual->prox;

    }
    return 0;
}

#endif
