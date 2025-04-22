#include <stdio.h>
#include <stdlib.h>


struct Data{
    int dia;
    int mes;
    int ano;
} *data, *data1, *data2;

int AlocaData(int d, int m, int a){
    data = malloc(sizeof(struct Data));

    data->dia = d;
    data->mes = m;
    data->ano = a;

    return data;

}


int diferencaDias(struct Data*data1, struct Data*data2){
    int total1 = data1->dia = data1->dia + (data1->mes * 30) + (data1->ano * 365);
    int total2 = data2->dia = data2->dia + (data2->mes * 30) + (data2->ano * 365);

    return abs(total1 - total2);
}

int main(){

data1 = AlocaData(5, 5, 2025);

data2 = AlocaData(5, 6, 2025);

printf("%d", diferencaDias(data1, data2));
    return 0;
}
