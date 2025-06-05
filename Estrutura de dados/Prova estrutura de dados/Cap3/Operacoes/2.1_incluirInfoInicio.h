#ifndef INCLUIR_INFO_INICIO_H
#define INCLUIR_INFO_INICIO_H

    void incluirInfoInicio(pDLista pd, void *info)
    {
        if (pd == NULL)
        {
            printf("Lista n�o existe ainda, n�o � poss�vel incluir algo em uma lista n�o existente.");
            return;
        }
        //Aloca mem�ria para guardar a nova informa��o
        pNoh pNovo = malloc(sizeof(Noh));

        //Atribuir o valor desejado ao espa�o de mem�ria pNovo
        pNovo->info = info;

        //salva a referencia ao primeiro noh da lista antes de atualizar o descritor
        pNoh auxPrimeiro = pd->primeiro;

        //o ultimo noh sera identificado como o ultimo da lista pelo descritor
        pd->primeiro = pNovo;

        //como a lista ganhou mais um componente, temos:
        pd->quantidade++;

        pNovo->prox = auxPrimeiro;

        //se o ponteiro � o �nico da fila, o descritor precisa atualizar tamb�m o ultimo da lista noh da lista
        if (pNovo->prox == NULL){
            pd->ultimo = pNovo;
        }
    }


#endif
