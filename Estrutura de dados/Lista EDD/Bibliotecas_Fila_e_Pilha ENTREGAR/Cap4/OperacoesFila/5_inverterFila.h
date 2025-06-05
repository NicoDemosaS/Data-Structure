#ifndef INVERTE_FILA_H
#define INVERTE_FILA_H

pDFila inverteFila(pDFila fila)
{
   pDPilha pilhas = criarPilha();

   while (filaVazia(fila)==0)
   {
    void *info = desenfileirarInfo(fila);
    empilharInfo(pilhas, info);
   }
   while(pilhaVazia(pilhas)==0)
   {
    enfileirarInfo(fila, desenfileirarInfo(pilhas));
   }
   free(pilhas);
   return fila;
}
#endif