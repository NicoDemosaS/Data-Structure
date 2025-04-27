#include <stdlib.h>
#include <stdio.h>

int proxPrimo(int primo){
    int i;
    primo = primo + 1;
    for(i=2;i<primo;i++){ 
        if((primo % i) == 0) // caso recursivo verifica se o numero e primo
            return proxPrimo(primo);
    }
       return primo;    
}


int mmc(int a, int b, int p){
    printf("mmc(a=%d, b=%d, p=%d)\n", a, b, p);
    if(a == 1 && b == 1) // caso base
        return 1;
    if(((a % p) == 0) && ((b % p) == 0)) // Se a e b forem divisiveis por p
        return p * mmc(a/p, b/p, p);
    if(((a % p) != 0) && ((b % p ) != 0)) // se a e b nao forem divisiveis por p
        return mmc(a, b, proxPrimo(p)); 
    if(((a % p) == 0) && ((b % p ) != 0)) // se somente a for divisivel por p
        return p * mmc(a/p ,b , p);  
    if(((a % p) != 0) && ((b % p) == 0)) // se somente b for divisivel por p
        return  p * mmc(a ,b/p , p);
}

void main(){
    printf("%d", mmc(12, 15, 2));
   

}