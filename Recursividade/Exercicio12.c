#include <stdio.h>

int descobrirPotencia(int num){
    int x = 1;
    int ultimaPotencia;
    while(x <= num){
        ultimaPotencia = x;
        x *= 2;
    }
    return ultimaPotencia;
}

int egipcio(int n1, int n2, int potencia, int soma){
    if (n2 == 0)
        return soma;
    if (n2 >= potencia){
        printf("Debug: n1 = %d, n2 = %d, potencia = %d, soma = %d\n", n1, n2, potencia, soma);
        soma += n1;
        n2 = n2 - potencia;
        
    }   
    return egipcio(n1 * 2, n2, potencia / 2, soma);
    }
    

void main() {
    int n1 = 12, n2 = 27;
    printf("Resultado de %d * %d = %d\n", n1, n2, egipcio(n1, n2, descobrirPotencia(n2), 0));
    //printf("Descobrir potencia 6 :%d", descobrirPotencia(6));
}