#ifndef MAIOR_FILA_H
#define MAIOR_FILA_H
#include <stdlib.h>

void* maiorInfo(pDFila fila, FuncaoComparacao fc){
    if (filaVazia(fila)) 
        return NULL;

    void* maior = desenfileirarInfo(fila);
    while (!filaVazia(fila)) {
        void* info = desenfileirarInfo(fila);
        if (fc(info, maior) < 0) { // se info é maior que maior
            maior = info;
        }
            // Necessario preservar a fila

    }
    return maior;
}


#endif