#ifndef ENFILEIRAR_INFO_FILA_H
#define ENFILEIRAR_INFO_FILA_H

void enfileirarInfo(pDFila pdFila, void *info){

   if (pdFila != NULL)
       incluirInfoInicio(pdFila->lista, info);
}

#endif
