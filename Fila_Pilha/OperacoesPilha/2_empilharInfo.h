#ifndef EMPILHAR_INFO_PILHA_H
#define EMPILHAR_INFO_PILHA_H

void empilharInfo(pDPilha pdPilha, void *info){
    incluirInfoFim(pdPilha->Lista_subjacente, info);
}

#endif
