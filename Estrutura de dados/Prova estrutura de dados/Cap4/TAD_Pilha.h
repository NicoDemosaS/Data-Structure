#ifndef PILHA_TAD_H
#define PILHA_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* descritor da pilha */
typedef struct dPilha DPilha;
typedef DPilha *pDPilha;

/* 3 tipos que representam ponteiros para fun��o */
typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPilha criarPilha();
void empilharInfo(pDPilha, void *);
void *desempilharInfo(pDPilha);
int pilhaVazia(pDPilha);
int  Iguais(pDPilha,pDPilha,FuncaoComparacao);
pDPilha copiaPilha(pDPilha,FuncaoAlocacao);
pDPilha interseccao(pDPilha, pDPilha, FuncaoComparacao);
int balanceamento(char expr[], int tamanho);
void limpaPilha(pDPilha );
int contida (pDPilha, pDPilha, FuncaoComparacao);
#endif