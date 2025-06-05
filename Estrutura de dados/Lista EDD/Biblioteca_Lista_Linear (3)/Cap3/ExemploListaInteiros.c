
#include "Utils.h"
#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pDLista pListaInt = criarLista();

    /* teste de inclusao */
    incluirInfo(pListaInt, alocaInt(1));
    incluirInfo(pListaInt, alocaInt(2));
    incluirInfo(pListaInt, alocaInt(4));
    incluirInfo(pListaInt, alocaInt(7));
    incluirInfo(pListaInt, alocaInt(6));
    incluirInfo(pListaInt, alocaInt(7));
    incluirInfo(pListaInt, alocaInt(3));
    incluirInfo(pListaInt, alocaInt(9));
    incluirInfo(pListaInt, alocaInt(1));

    printf("\nResultado da impressão \n");
    imprimirLista(pListaInt, imprimeInt);

    // INCLUIR INFO BASE AQUI! QUESTÃO 3 DA PROVA ##############
    int incluiu = incluirInfoBase (pListaInt, alocaInt(3), alocaInt(5), comparaInt);
    printf("\nA info foi incluída? sim[1] não [0]: %d\n", incluiu);
    imprimirLista(pListaInt, imprimeInt);


    /* teste de exclusao excluindo o número 9*/
    excluirInfo(pListaInt, alocaInt(9), comparaInt);
    printf("\nResultado da exclusao 9\n");
    imprimirLista(pListaInt, imprimeInt);

    // teste de add info em primeiro 3
    incluirInfoInicio(pListaInt, alocaInt(3));
    printf("\nResultado da adição do 3 em primeiro da fila\n");
    imprimirLista(pListaInt, imprimeInt);

    // incluir no meio o número 4
    incluirInfoMeio(pListaInt, alocaInt(4), 3);
    printf("\nResultado da adição num 4\n");
    imprimirLista(pListaInt, imprimeInt);

    /* teste de busca, número 5 */
    int result = contemInfo(pListaInt, alocaInt(5), comparaInt);
    printf("\nResultado da busca do n�mero 5: 0-[Nao encontrou], 1-[ok] -> %d\n", result);

    /* teste de duplicacao de lista */
    pDLista copia = duplicarLista(pListaInt, alocaInfoInt);
    printf("\nResultado da duplicacao \n");
    imprimirLista(copia, imprimeInt);

    // teste de divisao de lista
    // pDLista novaLista = dividirLista(pListaInt, 3);
    // printf("\nResultado da divisao \n");
    // printf("    Lista Original: ");
    // imprimirLista(pListaInt, imprimeInt);
    // printf("\n    Nova Lista: ");
    // imprimirLista(novaLista, imprimeInt);

    // dividir a lista pela info
    pDLista novaLista = dividirListaInfo(pListaInt, alocaInt(6), comparaInt);
    printf("\n\nResultado da divisão");
    printf("\n---Lista Original---\n");
    imprimirLista(pListaInt, imprimeInt);
    printf("\n---Nova Lista---\n");
    imprimirLista(novaLista, imprimeInt);

    // unir lista
    pDLista novaListaUn = unirLista(pListaInt, novaLista, comparaInt);
    printf("\n\nResultado da junção de listas\n");
    imprimirLista(novaListaUn, imprimeInt);

    // Unir lista com valores comuns
    pDLista novaListaCom = unirListaComum(pListaInt, novaLista, comparaInt);
    printf("\n\nResultado da junção de listas só com infos comuns\n");
    imprimirLista(novaListaCom, imprimeInt);

    // ver se as listas são disjuntas
    int disjuncao = disjuncaoListas(pListaInt, novaLista, comparaInt);
    printf("\n\nAs listas são disjuntas? se sim [1] se não [0]: %d\n\n", disjuncao);

    // ver se a lista é contida
    int listaContida = contida(novaLista, pListaInt, comparaInt);
    printf("\n\nA lista 2 está contida na lista 1? se sim [1] se não [0]: %d\n\n", listaContida);

    // inverter lista
    inverterLista(pListaInt);
    printf("\nlista invertida : \n");
    imprimirLista(pListaInt, imprimeInt);

    // inverter lista criando uma nova
    pDLista novaListaInvertida = inverterListaC(pListaInt);
    printf("\nInverter lista criando uma nova: \n");
    imprimirLista(novaListaInvertida, imprimeInt);

    printf("\n\nLista não invertida \n");
    imprimirLista(pListaInt, imprimeInt);

    printf("\nImprimindo lista recursiva!\n");
    imprimirListaRecursiva(pListaInt->primeiro, imprimeInt);

    // Teste maior info recursiva   QUESTÃO 1 DA PROVA ######################
    void *resp = maiorInfoRecursiva(pListaInt->primeiro, pListaInt->primeiro->info, comparaInt);
    printf("\nResultado do maior da lista: %d\n", *(int*)resp);

    /* teste de destruicao da lista */
    destruirLista(pListaInt);
    printf("\n\nResultado da destruicao da lista \n");
    imprimirLista(pListaInt, imprimeInt);
}
