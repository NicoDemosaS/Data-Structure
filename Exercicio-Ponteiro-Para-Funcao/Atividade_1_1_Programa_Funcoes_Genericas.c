#include <stdio.h>
#include "Atividade_1_1_FuncoesGenericas.h"
#include <stdlib.h>  


 //-----------------------
 int* alocaInt(int n){
    int* pi = malloc(sizeof(int));
    *pi = n;
    return pi;
 }

int  ContarPar(void *num){
   int *n1 = (int*) num;
   if(*n1 % 2 == 0) {
      return 1;
   }
   return 0;
}

void Dobra(void *num){
   int* n1 = (int*)num;
   *n1 = *n1 * 2;
   printf("%d/n", *n1);
}

int MaiorInt(void *num1, void *num2){
   int *n1 = (int*) num1;
   int *n2 = (int*) num2;
   return *n1 - *n2;
}


//--------------------------
int main(){
   int* v[5];
   int i;
   v[0] = alocaInt(6);
   v[1] = alocaInt(7);
   v[2] = alocaInt(15);
   v[3] = alocaInt(8);
   v[4] = alocaInt(12);
   //int* resultado = encontrarMaior((void**)v, 5, MaiorInt);

   //printf("Maior: %d", *resultado);
   printf("Maior : %d", *(int*)encontrarMaior((void**)v, 5, MaiorInt));
   return 0;
}
