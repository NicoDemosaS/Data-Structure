#ifndef QUERYALL_H
#define QUERYALL_H


pDLista queryAll(pDFile arq){

   if (arq->arquivo == NULL){
       printf("Arquivo n�o foi aberto!");
       return NULL;
   }
    pDLista todos = criarLista();
    void* registro = malloc(arq->tamanhoRegistro);
    void* vazio = malloc(arq->tamanhoRegistro);
    memset(vazio, 0, arq->tamanhoRegistro);
    rewind(arq->arquivo);
    while(fread(registro, arq->tamanhoRegistro, 1, arq->arquivo) != 0){

        if(memcmp(vazio, registro, arq->tamanhoRegistro) != 0){
            // printf("Incluindo um registro"); // Somente para debugar
            incluirInfoFim(todos, registro);
            registro = malloc(arq->tamanhoRegistro);
        }
    }

    return todos;

}

#endif
