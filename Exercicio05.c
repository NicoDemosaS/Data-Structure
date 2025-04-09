#include <stdio.h>
#include <stdlib.h>


struct Data{
    int dia;
    int mes;
    int ano;
} *data1, *data2;

int diferencaDias(struct Data*data1, struct Data*data2){
    int total1 = data1->dia = data1->dia + (data1->mes * 30) + (data1->ano * 365);
    int total2 = data2->dia = data2->dia + (data2->mes * 30) + (data2->ano * 365);

    return abs(total1 - total2);
}

int main(){
   

data1 = malloc(sizeof(struct Data));
data2 = malloc(sizeof(struct Data));

data1->dia = 5;
data1->mes = 2;
data1->ano = 2025;


data2->dia = 5;
data2->mes = 2;
data2->ano = 2026;


printf("%d", diferencaDias(data1, data2));
    return 0;
}