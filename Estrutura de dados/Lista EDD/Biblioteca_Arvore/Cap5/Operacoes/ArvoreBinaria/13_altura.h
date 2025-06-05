#ifndef ALTURA_ARVORE_H
#define ALTURA_ARVORE_H

int alturaArvoreRecursiva(pNohArvore raiz)
{
   if (raiz == NULL)
   {
      return 0;
   }

   if (raiz->direita == NULL && raiz->esquerda == NULL)
   {
      return 0;
   }

   if (raiz->direita == NULL)
   {
      return alturaArvoreRecursiva(raiz->esquerda) + 1;
   }

   if (raiz->esquerda == NULL)
   {
      return alturaArvoreRecursiva(raiz->direita) + 1;
   }

   int alturaEsquerda = alturaArvoreRecursiva(raiz->esquerda);
   int alturaDireita = alturaArvoreRecursiva(raiz->direita);

   return (alturaEsquerda > alturaDireita ?alturaEsquerda:alturaDireita) + 1;
}

/*----------------------------------------------------------------------------------------------*/

int alturaArvore(pDArvore arvore)
{
   return alturaArvoreRecursiva(arvore->raiz);
}
#endif
