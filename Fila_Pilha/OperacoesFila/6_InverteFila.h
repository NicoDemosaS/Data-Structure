#ifndef INVERTE_FILA_H
#define INVERTE_FILA_H
#include <stdlib.h>

pDFila inverteFila(pDFila fila){
    pDFila FilaInvertida = criarFila();
    pDPilha pilhaAuxiliar = criarPilha();
    void *info;

    while(filaVazia(fila) == 0){
        info = desenfileirarInfo(fila);
        empilharInfo(pilhaAuxiliar, info);
    }
    while(pilhaVazia(pilhaAuxiliar) == 0){
        info = desempilharInfo(pilhaAuxiliar);
        enfileirarInfo(FilaInvertida, info);
    }


    return FilaInvertida;

}



#endif