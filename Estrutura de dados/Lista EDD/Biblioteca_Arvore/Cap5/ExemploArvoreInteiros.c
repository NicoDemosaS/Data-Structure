#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main()
{
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */

    incluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(3), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(9), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(8), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(1), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(2), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(0), comparaInt);

    // Arvore similar
    pDArvore pArvoreInt3 = criarArvore(2);

    /* teste de inclusao */

    incluirInfo(pArvoreInt3, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt3, alocaInt(3), comparaInt);
    incluirInfo(pArvoreInt3, alocaInt(9), comparaInt);
    incluirInfo(pArvoreInt3, alocaInt(8), comparaInt);
    incluirInfo(pArvoreInt3, alocaInt(1), comparaInt);
    incluirInfo(pArvoreInt3, alocaInt(2), comparaInt);
    incluirInfo(pArvoreInt3, alocaInt(0), comparaInt);

    pDArvore pArvoreInt2 = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt2, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt2, alocaInt(3), comparaInt);
    incluirInfo(pArvoreInt2, alocaInt(9), comparaInt);
    incluirInfo(pArvoreInt2, alocaInt(1), comparaInt);
    incluirInfo(pArvoreInt2, alocaInt(2), comparaInt);

    //QUESTÃO 1 DA PROVA, SOMA DE NOH MAPEADO 
    int somaNohMap = somaNohMapeado(pArvoreInt, mapeaInt);
    printf("\nSoma dos nohs mapeados: %d\n", somaNohMap);

    // QUESTÃO 2 DA PROVA, ARVORES SIMILARES

    int comparaSimilares = similares(pArvoreInt, pArvoreInt3);
    printf("Se similares {0} se diferentes {1}: %d", comparaSimilares);

    // QUESTÃO 4 DA PROVA, QUANTIDADE DE NÓS DA ÁRVORE MAIOR QUE VALOR DADO
    int quantidadeDeMaiores = qtdeMaiores(pArvoreInt, alocaInt(6), comparaInt);
    printf("\nQuantidade de valores maiores na árvore: %d\n", quantidadeDeMaiores);

    // QUESTÃO 3 DA PROVA, FILHO ÚNICO
    int QuantFilhoUnico = SomenteUmFilho(pArvoreInt);
    printf("\nNúmero de filhos únicos na árvore: %d\n", QuantFilhoUnico);

    // print quantidade de nohs por nível
    int nohsPorNivel = quantidadeNohsNivel(pArvoreInt, 2, comparaInt);
    printf("\na quantidade de nohs por nível são: %d\n", nohsPorNivel);

    // print da arvore usada em questão
    printf("\nArvore int 1\n");
    desenhaArvore(pArvoreInt, imprimeInt);
    printf("\n");

    float media = mediaNohs(pArvoreInt);
    printf("\nmédia da soma da árvore: %.2f\n", media);

    float mediaDeFolhas = mediaFolhas(pArvoreInt);
    printf("\nmédia das folhas da arvore: %.2f\n", mediaDeFolhas);

    // Teste caminho entre nohs
    printf("Teste de caminho entre nohs");
    int val = 0;
    int caminho = 0;
    int caminhoEntreNohs = caminhoNohs(pArvoreInt, alocaInt(3), alocaInt(0), comparaInt, caminho, val);
    printf("\no caminho entre os nohs informados tem o comprimento de: %d", caminhoEntreNohs);
    printf("\nDe 3 até 0\n");

    // teste nível
    printf("\nTeste do nível de um noh\n");
    int aux = 0;
    int nivelProf = nivel(pArvoreInt, alocaInt(8), comparaInt, aux);
    printf("o nível de profundidade é: %d", nivelProf);

    // Teste é folha
    printf("\nTeste de é folha (a partir de uma info)\n");
    int existeFolha = ehFolha(pArvoreInt, alocaInt(0), comparaInt);
    printf("\nse {1} é folha, se {0} não é folha: %d\n", existeFolha);

    emOrdem(pArvoreInt->raiz, imprimeInt);
    printf("\n");

    printf("\nTeste de arvore balanceada\n");

    int balan = balanceada(pArvoreInt);

    printf("\nSe sim{1} se não{0}: %d\n", balan);

    printf("\n");

    amplitude(pArvoreInt, imprimeInt, comparaInt);

    printf("\n");

    int comprimentoArvore = comprimentoInterno(pArvoreInt);
    printf("\nComprimento interno da árvore: %d\n", comprimentoArvore);

    int quant = quantidadeNohs(pArvoreInt);
    printf("\nquant nohs árvore: %d\n", quant);

    // Teste de árvores iguais
    printf("\nTeste de Árvore Igual\n");
    int igual = arvoreIgual(pArvoreInt, pArvoreInt2, comparaInt);
    printf("\n\nse {0} diferente, se {1} igual: %d\n\n", igual);

    // Teste de árvore binária
    printf("\nTeste de Árvore Binária\n");
    int arvoreBinaria = estritamenteBinaria(pArvoreInt);
    printf("\n\nse {0} não binária, se {1} binária: %d\n\n", arvoreBinaria);

    // Teste Espelhamento de árvore
    printf("\nEspelhamento de uma árvore\n");
    printf("\nAntes");
    desenhaArvore(pArvoreInt2, imprimeInt);

    printf("\nDepois");
    espelhamento(pArvoreInt2);
    desenhaArvore(pArvoreInt2, imprimeInt);

    // alturaArvore(pArvoreInt);
    int altura = alturaArvore(pArvoreInt);
    printf("\nAltura da árvore: %d\n", altura);

    desenhaArvore(pArvoreInt, imprimeInt);
    pNohArvore infoRaiz = buscarInfo(pArvoreInt,
                                     alocaInt(9), comparaInt);
    if (infoRaiz != NULL)
        imprimeInt(infoRaiz->info);
    printf("\n");
    printf("\n");
    preOrdem(pArvoreInt->raiz, imprimeInt);
    printf("\n");
    posOrdem(pArvoreInt->raiz, imprimeInt);

    printf("\n");
    printf("\n");
    /* teste de exclusao */
    int res = excluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    printf("\nExcluiu? = %d \n", res);
    desenhaArvore(pArvoreInt, imprimeInt);
    printf("\n");
    emOrdem(pArvoreInt->raiz, imprimeInt);
    printf("\n");
    printf("\n");

    int folhas = quantidadeFolhas(pArvoreInt);
    printf("\nQuantidade de folhas = %d \n", folhas);
}
