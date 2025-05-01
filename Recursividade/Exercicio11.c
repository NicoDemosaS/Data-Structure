#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contarDigitos(int num){
    int cont = 0;
    while(num > 0){
        num = num / 10;
        cont++;
    }
    return cont;

}

int palinDromo(int num){
        int digitos = contarDigitos(num);
        if(digitos == 1 || digitos == 0)
            return 1; // caso base, e palindromo!

        int primeiroDigito = num / pow(10, digitos-1);
        int ultimoDigito = num % 10;

        if(primeiroDigito!= ultimoDigito){
            printf("Nao e palindromo!");
            return 0;
        } // caso base se primeiro digito for diferente do ultimo

        if(primeiroDigito == ultimoDigito){
            int restante = (num % (int)pow(10, digitos - 1)) / 10;
          
            return palinDromo(restante);
        }
}

void main(){
    /*Escreva uma func¸˜ao recursiva que verifica se um n ´umero
inteiro ´e pal´ındromo. O n´umero 53235 ´e pal´ındromo.*/
    printf("%d", palinDromo(53235));

}