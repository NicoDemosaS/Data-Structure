#ifndef BALANCEAMENTO_PILHA_H
#define BALANCEAMENTO_PILHA_H
#include <stdio.h>

int removePorInfo(pDPilha pilha, void *info, FuncaoComparacao fc){
    pDPilha pilhaAuxiliar = criarPilha();
    void *aux;
    while(pilhaVazia(pilha) == 0){
        aux = desempilharInfo(pilha);
        empilharInfo(pilhaAuxiliar, aux);

        if(fc(aux, info) == 0){
            desempilharInfo(pilhaAuxiliar);
            break;
        }
    }

    while(pilhaVazia(pilhaAuxiliar) == 0){
        aux = desempilharInfo(pilhaAuxiliar);
        empilharInfo(pilha, aux);
    }

}


#endif