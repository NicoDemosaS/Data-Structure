#include <stdio.h>
#include <stdlib.h>


struct Ponto2D{
    float ponto1;
    float ponto2;
}*pontoA, *pontoB;

float distancia(struct Ponto2D*pontoA, struct Ponto2D*pontoB){
    float soma_pontoA = (pontoA->ponto1 + pontoA->ponto2);
    float soma_pontoB = (pontoB->ponto1 + pontoB->ponto2);

    return (soma_pontoA - soma_pontoB);
}

int main(){
   pontoA = malloc(sizeof(struct Ponto2D));
   pontoB = malloc(sizeof(struct Ponto2D));

    pontoA->ponto1 = 5;

    pontoA->ponto2 = 10;

    pontoB->ponto1 = 10;

    pontoB->ponto2 = 10;

    printf("%.2f", distancia(pontoA, pontoB));


    return 0; 
}