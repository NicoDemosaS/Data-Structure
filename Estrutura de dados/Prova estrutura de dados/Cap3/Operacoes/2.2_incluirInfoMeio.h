#ifndef INCLUIR_INFO_MEIO_H
#define INCLUIR_INFO_MEIO_H


void incluirInfoMeio(pDLista pd, void *info, int pos)
{

    if (pd == NULL)
    {
        printf("Lista n�o existe ainda, n�o � poss�vel incluir algo em uma lista n�o existente.");
        return;
    }
    // Aloca mem�ria para guardar a nova informa��o
    pNoh pNovo = malloc(sizeof(Noh));

    // Atribuir o valor desejado ao espa�o de mem�ria pNovo
    pNovo->info = info;

    int cont = 1;
    pNoh atual, ant;

    atual = pd->primeiro;
    ant = NULL;

    // encontrar o Noh da possição desejada

    while (atual != NULL && cont < pos)
    {
        ant = atual;
        atual = atual->prox;
        cont++;
    }

    ant->prox = pNovo;
    pNovo->prox = atual;
}


#endif