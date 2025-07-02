  #ifndef UPDATE_H
#define UPDATE_H

void update(pDFile arq, void* chave, void* dados, FuncaoComparacao pfc){

    if (arq->arquivo == NULL){
       printf("Arquivo não foi aberto!");
       return;
   }

   void* registro = malloc(arq->tamanhoRegistro);

   int flag = 0;

   rewind(arq->arquivo);
   while(fread(registro, arq->tamanhoRegistro, 1, arq->arquivo) != 0){

       if (pfc(chave, registro) == 0){
            flag = 1;
           break;
       }
   }

   if (flag == 1){

      // atualiza o cadastro
      fseek(arq->arquivo, -arq->tamanhoRegistro, SEEK_CUR);
      fwrite(dados, arq->tamanhoRegistro, 1, arq->arquivo);

   }



}

#endif