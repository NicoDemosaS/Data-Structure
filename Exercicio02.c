#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pLados;
    int i;
    pLados = malloc(sizeof(int) * 3);
    // i = malloc(sizeof(int));
    for(i=0;i<3;i++){
        scanf("%d", pLados+i);
    }
    if(*(pLados) == *(pLados+1) && *(pLados + 1) == *(pLados + 2)){
        printf("Equilatero");
        return 0;
    }
    if(*(pLados) != *(pLados+1) && *(pLados + 1) != *(pLados + 2)){
        printf("Escaleno");
        return 0;
    }
    if(*(pLados) == *(pLados+1) || *(pLados + 1) == *(pLados + 2)){
        printf("Isosceles");
        return 0;
    }
    return 0;
}