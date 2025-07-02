#ifndef RETRIEVE_H
#define RETRIEVE_H

void* retrieve  (pDFile arq, void* chave, FuncaoComparacao pfc){
    void *registro = malloc(arq->tamanhoRegistro);


    rewind(arq->arquivo);
    while(fread(registro, arq->tamanhoRegistro, 1, arq->arquivo) != 0){

        if(pfc(registro, chave) == 0){
            return registro;
        }
    }
    
    return NULL;
}


#endif
