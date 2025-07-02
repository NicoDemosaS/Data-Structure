#ifndef IMPRIMIR_RECURSIVO_LISTA_H
#define IMPRIMIR_RECURSIVO_LISTA_H
#include "../Utils.h"


void ImprimirListaRecursivaAux(pNoh atual, FuncaoImpressao fi) {
    if (atual == NULL) return;
    fi(atual->info);
    ImprimirListaRecursivaAux(atual->prox, fi);
}

void ImprimirListaRecursiva(pDLista lista, FuncaoImpressao fi){
    ImprimirListaRecursivaAux(lista->inicio, fi);
}





#endif