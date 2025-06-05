#ifndef ESPELHAMENTO_H
#define ESPELHAMENTO_H

/*----------------------------------------------------------------------------------------------*/

pDArvore espelhamento(pDArvore arv)
{

  pNohArvore raizDireita = arv->raiz->direita;
  pNohArvore raizEsquerda = arv->raiz->esquerda;
  pDArvore auxArvore = arv;

  auxArvore->raiz->esquerda = raizDireita;
  auxArvore->raiz->direita = raizEsquerda;
  
  return auxArvore;
}

#endif
