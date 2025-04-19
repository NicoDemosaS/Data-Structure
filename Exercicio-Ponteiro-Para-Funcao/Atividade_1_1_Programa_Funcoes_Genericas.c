#include <stdio.h>
#include "Atividade_1_1_FuncoesGenericas.h"
#include <stdlib.h>  


 //-----------------------

void iniciarBaralho(struct CartaBaralho baralho[]){
   int j, i, index = 0;
   char naipes[] = {'C', 'O', 'E', 'P'}; // C = Copas, O = Ouros, E = Espadas, P = Paus
   for(i=0;i<13;i++){
      for(j=0;j<4;j++){
         baralho[index].valor = i;
         baralho[index].naipe = naipes[j];
         index++;
      }
   }
}

int AcharCoringa(struct CartaBaralho Carta, struct CartaBaralho Vira){
   if(Carta.valor == Vira.valor + 1 && Carta.naipe == Vira.naipe){
      return 1;
   }
     return 0;
}

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

   /*printf("Maior: %d", *resultado);
   printf("Maior : %d", *(int*)encontrarMaior((void**)v, 5, MaiorInt)); */
   
  
   struct CartaBaralho baralho[52];
   iniciarBaralho(baralho);
   printf("Carta vira -> Valor: %d, Naipe: %c\n", baralho[12].valor, baralho[12].naipe);
   identificarCoringa(baralho, 52, baralho[12], AcharCoringa);


}
