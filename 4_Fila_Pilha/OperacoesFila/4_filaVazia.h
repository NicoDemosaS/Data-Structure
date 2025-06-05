#ifndef ESTAVAZIA_FILA_H
#define ESTAVAZIA_FILA_H

int filaVazia(pDFila pdFila){
  if (pdFila == NULL)
    return 1;

  if(pdFila->lista->quantidade == 0)
        return 1;

    return 0;


   // pdFila->lista->quantidade == 0 ? 1 : 0;

}
#endif
