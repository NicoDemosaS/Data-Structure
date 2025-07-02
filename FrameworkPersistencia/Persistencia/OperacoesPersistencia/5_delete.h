#ifndef DELETE_H
#define DELETE_H

void deletee(pDFile arq, void* chave, FuncaoComparacao pfc){
    
    if(arq->arquivo == NULL){
        printf("Arquivo não foi aberto!");
        return;
   }

   void* registro = malloc(arq->tamanhoRegistro);

    while(fread(registro, arq->tamanhoRegistro, 1, arq->arquivo) != 0){
        if(pfc(chave, registro) == 0){
            // printf("Registro encontrado");
            fseek(arq->arquivo, -arq->tamanhoRegistro, SEEK_CUR);
            memset(registro, 0, arq->tamanhoRegistro);
            fwrite(registro, 1, arq->tamanhoRegistro, arq->arquivo);
            // printf("MEMSET feito!");
            return;
        }
    }
}

#endif
