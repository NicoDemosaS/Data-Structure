#ifndef DESENFILEIRAR_INFO_FILA_H
#define DESENFILEIRAR_INFO_FILA_H

void* desenfileirarInfo(pDFila pdFila){

   if(pdFila != NULL)
      return excluirInfoPos(pdFila->lista, 1); // Vai retirando sempre do inicio

   return NULL;
}

#endif
