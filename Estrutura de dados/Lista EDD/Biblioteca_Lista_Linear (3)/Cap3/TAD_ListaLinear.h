#ifndef LISTA_TAD_H
#define LISTA__TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh Noh;
typedef Noh *pNoh;

/* descritor da lista */
typedef struct dLista DLista;
typedef DLista *pDLista;

/* 3 tipos que representam ponteiros para fun��o */
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void *(*FuncaoAlocacao)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista criarLista();
void incluirInfo(pDLista, void *);
int excluirInfo(pDLista, void *, FuncaoComparacao);
int contemInfo(pDLista, void *, FuncaoComparacao);
void imprimirLista(pDLista, FuncaoImpressao);
void destruirLista(pDLista);
pDLista duplicarLista(pDLista, FuncaoAlocacao);
/* o parametro int estabelece a posicao da lista onde a divisao deve acontecer */
pDLista dividirLista(pDLista, int);
void *buscarNohInfo(pDLista, void *, FuncaoComparacao);
void incluirInfoInicio(pDLista pd, void *info);
void incluirInfoMeio(pDLista pd, void *info, int pos);
pDLista dividirLista(pDLista, int);
pDLista dividirListaInfo(pDLista, void *info, FuncaoComparacao pfc);
pDLista unirLista(pDLista, pDLista, FuncaoComparacao pfc);
pDLista unirListaComum(pDLista, pDLista, FuncaoComparacao pfc);
int disjuncaoListas(pDLista lista1, pDLista lista2, FuncaoComparacao pfc);
int contida(pDLista lista1, pDLista lista2, FuncaoComparacao fc);
pDLista inverterLista(pDLista lista1);
pDLista inverterListaC(pDLista lista);
void imprimirListaRecursiva(pNoh atual, FuncaoImpressao pfi);
void* maiorInfoRecursiva (pNoh noh, void* maiorAtual, FuncaoComparacao fc);
int incluirInfoBase (pDLista, void*, void*, FuncaoComparacao);

#endif
