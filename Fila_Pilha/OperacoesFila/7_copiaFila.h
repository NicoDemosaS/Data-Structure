#ifndef INVERTE_FILA_H
#define INVERTE_FILA_H
#include <stdlib.h>

pDFila copiaFila(pDFila fila, FuncaoAlocacao fa){
    pDFila filaCopiada = criarFila();
    pDFila filaAuxiliar = criarFila();
    void *info;

    void *infoCopy;
    while(filaVazia(fila) == 0){
        info = desenfileirarInfo(fila);
        enfileirarInfo(filaAuxiliar, info);

        infoCopy = fa(info);
        enfleirarInfo(filaCopiada, infoCopy);
    }

    while(filaVazia(filaAuxiliar) == 0){
        info = desenfileirarInfo(filaAuxiliar);
        enfileirarInfo(fila, info);
    }

    return filaCopiada;




}




#endif