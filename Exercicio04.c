#include <stdio.h>
#include <stdlib.h>

int maior(int*vetor, int tam){
    int i, *maior;
    maior = malloc(sizeof(int));
    *maior = *vetor;
    for(i=0;i<tam;i++){
        if(*(vetor + i) > *maior)
            *maior = *(vetor + i);
    }
    return *maior;
}


int main(){
    int n, i;
    int *p;
    printf("Quantos numeros a alocar: ");
    scanf("%d", &n);
    p = malloc(sizeof(int) * n);
    for(i=0;i<n;i++){
        scanf("%d", p+i);
    }

    // Printando o vetor.
    for(i=0;i<n;i++){
        printf("%d \n", *(p+i));
    }

    printf("Maior: %d", maior(p, n));
    return 0;
}
