#ifndef PILHAVAZIA_PILHA_H
#define PILHAVAZIA_PILHA_H

int pilhaVazia(pDPilha pdPilha){

    if (pdPilha == NULL || pdPilha->Lista_subjacente->quantidade == 0)
        return 1;

    return 0;
}

#endif
