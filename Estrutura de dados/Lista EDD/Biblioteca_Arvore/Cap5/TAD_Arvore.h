#ifndef ARVORE_TAD_H
#define ARVORE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct nohArvore NohArvore;
typedef NohArvore *pNohArvore;

/* descritor da arvore */
typedef struct dArvore DArvore;
typedef DArvore *pDArvore;

/* tipos referentes aos ponteiros para funcao */
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef int (*FuncaoMapeamento)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDArvore criarArvore(int);

void incluirInfo(pDArvore, void *, FuncaoComparacao);
int excluirInfo(pDArvore, void *, FuncaoComparacao);
pNohArvore buscarInfo(pDArvore, void *, FuncaoComparacao);
int quantidadeNohs(pDArvore);

/* percursos */
void emOrdem(pNohArvore, FuncaoImpressao);
void preOrdem(pNohArvore, FuncaoImpressao);
void posOrdem(pNohArvore, FuncaoImpressao);

int grau(pDArvore);
int nivel(pDArvore, void *, FuncaoComparacao, int);
int quantidadeFolhas(pDArvore);
int ehFolha(pDArvore, void *, FuncaoComparacao);
int arvoreVazia(pDArvore);
int alturaArvore(pDArvore);
int arvoreIgual(pDArvore, pDArvore, FuncaoComparacao);
int estritamenteBinaria(pDArvore);
pDArvore espelhamento(pDArvore);
int comprimentoInterno(pDArvore);
int balanceada(pDArvore);
void amplitude(pDArvore, FuncaoImpressao, FuncaoComparacao);
pNohArvore minValue(pDArvore);
pNohArvore maxValue(pDArvore);
int isBST(pDArvore, void *, void *);
int caminhoNohs(pDArvore, void *, void *, FuncaoComparacao, int, int);
void desenhaArvore(pDArvore, FuncaoImpressao);
int quantidadeNohsNivel(pDArvore, int, FuncaoComparacao);
float mediaNohs(pDArvore);
float mediaFolhas(pDArvore);
int SomenteUmFilho(pDArvore);
int qtdeMaiores(pDArvore, void *, FuncaoComparacao);
int similares(pDArvore arvore1, pDArvore arvore2);
int somaNohMapeado (pDArvore, FuncaoMapeamento);

#endif
