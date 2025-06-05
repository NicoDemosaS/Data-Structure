#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Pilha.h"

// a funcao abaixo verifica se umma sequencia de caractteres é palindroma, usando pilhas
int palindromo(char *str)
{
    pDPilha pPilhaChar = criarPilha();
    int i = 0;
    while (str[i] != '\0')
    {
        empilharInfo(pPilhaChar, alocaChar(str[i]));
        i++;
    }
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != *((char *)desempilharInfo(pPilhaChar)))
        {
            // se o caractere atual for diferente do caractere desempilhado, a sequencia nao é palindroma
            return 0;
        }
        i++;
    }
    // se a pilha estiver vazia, a sequencia é palindroma
    return 1;
}

int main()
{
    pDPilha pPilhaInt = criarPilha();

    /* teste de empilhamento */
    empilharInfo(pPilhaInt, alocaInt(5));
    empilharInfo(pPilhaInt, alocaInt(3));
    empilharInfo(pPilhaInt, alocaInt(9));
    empilharInfo(pPilhaInt, alocaInt(1));
    empilharInfo(pPilhaInt, alocaInt(2));

    pDPilha pPilhaInt2 = criarPilha();

    /* teste de empilhamento */
    empilharInfo(pPilhaInt2, alocaInt(5));
    empilharInfo(pPilhaInt2, alocaInt(2));
    empilharInfo(pPilhaInt2, alocaInt(9));
    empilharInfo(pPilhaInt2, alocaInt(1));
    empilharInfo(pPilhaInt2, alocaInt(2));

    printf("\n");
    imprimirLista(pPilhaInt->pdLista, imprimeInt);
    printf("\n");
    imprimirLista(pPilhaInt2->pdLista, imprimeInt);
    printf("\n");

    printf("\n\n\n\nRODOU\n\n\n\n");

    // ver se a lista é contida QUESTÃO 4 DA PROVA ####################################
    int pilhaContida = contida(pPilhaInt, pPilhaInt2, comparaInt);
    printf("\n\nA lista 2 está contida na lista 1? se sim [1] se não [0]: %d\n\n", pilhaContida);

    // teste se pilhas são iguais
    printf("Teste se as pilhas são iguais");
    int resp = Iguais(pPilhaInt, pPilhaInt2, comparaInt);
    printf("\nse iguais [1] se diferentes [0]: %d\n", resp);

    // duplicar a pilha
    pDPilha pilhaCopiada = copiaPilha(pPilhaInt, alocaInfoInt);
    printf("\nFila duplicada\n");
    imprimirLista(pPilhaInt->pdLista, imprimeInt);
    printf("\n");
    imprimirLista(pilhaCopiada->pdLista, imprimeInt);
    printf("\n");

    pDPilha novaPilhaCom = interseccao(pPilhaInt, pPilhaInt2, comparaInt);
    printf("\n\nResultado da junção de listas só com infos comuns\n");
    imprimirLista(novaPilhaCom->pdLista, imprimeInt);

    /* teste de desempilhamento */
    void *info = desempilharInfo(pPilhaInt);
    printf("\nDesempilhou o inteiro = %d \n", *((int *)info));

    while (pilhaVazia(pPilhaInt) == 0)
    {
        info = desempilharInfo(pPilhaInt);
        printf("\nDesempilhou o inteiro = %d \n", *((int *)info));
    }

    char str[] = "arara";
    if (palindromo(str) == 0)
    {
        printf("Não é palindromo!");
    }
    else
    {
        printf("É palindromo!");
    }

    


    /* teste balanceamento */
    char expressao1[] = "(2 + 3) * (4 - 1)"; // balanceada
    char expressao2[] = "((2 + 3) * (4 - 1)"; // não balanceada

    int tamanho1 = sizeof(expressao1) / sizeof(expressao1[0]) - 1; // Tamanho da expressão1
    int tamanho2 = sizeof(expressao2) / sizeof(expressao2[0]) - 1; // Tamanho da expressão2

    int balanceamento1 = balanceamento(expressao1, tamanho1);
    printf("\n\n Balanceamento expressão 1 (2 + 3) * (4 - 1)=  %d  (0-Desbalanceada, 1-Balanceada)", balanceamento1);

    int balanceamento2 = balanceamento(expressao2, tamanho2);
    printf("\n\n Balanceamento expressão 2 ((2 + 3) * (4 - 1)=  %d  (0-Desbalanceada, 1-Balanceada)", balanceamento2);

}
