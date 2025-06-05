#ifndef DECOMPOR_LISTA_H
#define DECOMPOR_LISTA_H
#include "../Utils.h"


pDLista decomporNumero(int n) {
    pDLista lista = criarLista();
    int expoente = 0;
    int base = 10;

    if (n == 0) {
        struct decomposto* d = malloc(sizeof(struct decomposto));
        d->coeficiente = 0;
        d->base = base;
        d->expoente = 0;
        incluirInfoInicio(lista, d);
        return lista;
    }

    while (n > 0) {
        int digito = n % base;
        struct decomposto* d = malloc(sizeof(struct decomposto));
        d->coeficiente = digito;
        d->base = base;
        d->expoente = expoente;
        incluirInfoInicio(lista, d); // mais significativo no início
        n = n / base;
        expoente++;
    }
    return lista;
}

#endif