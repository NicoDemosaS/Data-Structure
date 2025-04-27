#include <stdlib.h>
#include <stdio.h>

int perc(int h, float r){
    if(h <= 0) // caso base
        return 0;
    if(h > 0)
        return h + (h * r) + perc(h * r, r); // caso recursiva
}

void main(){
    printf("%d" , perc(12, 0.3));
}