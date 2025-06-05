#ifndef FILA_TAD_H
#define FILA_TAD_H

/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* descritor da fila */
typedef struct dFila DFila;
typedef DFila *pDFila;

/* 3 tipos que representam ponteiros para fun��o */
typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDFila criarFila();
void enfileirarInfo(pDFila, void *);
void *desenfileirarInfo(pDFila);
int filaVazia(pDFila);
pDFila inverteFila(pDFila fila);
pDFila copia(pDFila fila, FuncaoAlocacao fa);
void troca(pDFila fila, void *a, void *b, FuncaoComparacao pfc);
#endif
