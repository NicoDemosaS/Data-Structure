#include <stdio.h>
#include <stdlib.h>

int *n;
int *num;
int *divisores;
int i, soma;
int *j;
int perfeito(int *n){
    j = malloc(sizeof(int));
    *j = 0;
    soma = 0;
    divisores = malloc(sizeof(int) * *n);
    for(i=1;i<*n;i++){
        if((*n % i) == 0){
            *(divisores+*j) = i;
            (*j)++;
        }
    }
    for(i=0;i<*j;i++){
        //printf("%d", *(divisores+i));
        soma += *(divisores+i);
    }
        if(soma == *n)
            return 1;
        if(soma != *n)
            return 0; 
    

}


void main(){
    num = malloc(sizeof(int));
    scanf("%d", num);
    if(perfeito(num) == 1)
        printf("Numero Perfeito\n");
    if(perfeito(num) == 0)
        printf("Nao perfeito.\n");
}