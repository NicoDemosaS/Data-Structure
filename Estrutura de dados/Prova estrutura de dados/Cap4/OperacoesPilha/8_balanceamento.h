#ifndef BALANCEAMENTO_PILHA_H
#define BALANCEAMENTO_PILHA_H
#include <stdio.h>
int balanceamento(char expr[], int tamanho)
{
    int contador = 0; // o cont irá ajudar a checar se há parenteses

    for (int i = 0; i < tamanho; i++)
    {
        if (expr[i] == '(')
        {
            contador++; // se tem um parenteses de abertura, o contador soma +1
        }
        else if (expr[i] == ')')
        {
            contador--; // se tem o parenteses de fechamento, subtrai do cont

            // se o cont ficar negativo, parenteses de fechamento não tem seu par de abertura

            if (contador != 0)
            {
                return 0; // Expressão não está balanceada
            }
        }
    }

    return 1;
}

#endif