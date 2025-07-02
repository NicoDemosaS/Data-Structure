#ifndef DESEMPILHAR_INFO_PILHA_H
#define DESEMPILHAR_INFO_PILHA_H

void* desempilharInfo(pDPilha pdPilha){
   int ultimo = pdPilha->Lista_subjacente->quantidade;
 
   if (pdPilha != NULL && pilhaVazia(pdPilha)==0){
       return excluirInfoPos(pdPilha->Lista_subjacente, ultimo);
   }
   return NULL;
  
}

#endif
