#include <stdio.h>
#include <stdlib.h>

void main(){
    void *pNum1;
    void *pNum2;

    pNum1 = malloc(sizeof(int));
    pNum2 = malloc(sizeof(int));

    scanf("%d", pNum1);
    scanf("%d", pNum2);

    printf("%.2f", (*((int*)pNum1) + *((int*)pNum2)) / 2.0);
}