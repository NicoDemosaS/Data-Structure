Universidade Tecnológica Federal do Paraná - UTFPR
Campus Medianeira
Disciplina : CM1009 – Fundamentos de Estrutura de Dados
EXERCÍCIOS COM PONTEIROS E ALOCAÇÃO DE MEMÓRIA
Instrução para a resolução das questões:
• Não utilize variáveis estáticas, ou seja, utilize somente ponteiros e alocação
dinâmica de memória para armazenar as informações necessárias de cada
programa.
1. [PONTEIRO E MALLOC] Escreva um programa em C que leia 2 numeros reais e imprime
a media deles.
2. [PONTEIRO E MALLOC] Escreva um programa em C que leia 3 numeros inteiros e
informa o tipo de triangulo formado pelos 3 numeros.
- Equilátero : 3 lados iguais
- Isósceles : 2 lados iguais
- Escaleno : todos os lados diferentes
3. [PONTEIRO E MALLOC] Escreva um programa em C que leia um numero inteiro e
determina se e um numero perfeito.
Um numero e perfeito se a soma dos seus divisores e igual ao proprio numero. Por
exemplo, o numero 6 e perfeito, pois a soma dos seus divisores - 1 + 2 + 3 – e igual a 6.
A logica do programa para determinar se um numero e perfeito deve ser implementada
com uma funçao.
int perfeito(int *n)
4. [PONTEIRO COM VETOR] Escreva um programa em C que leia um numero inteiro N e,
em seguida, aloque memoria suficiente para armazenar N numeros inteiros.
Escreva tambem uma funçao que receba os N numeros inteiros e retorne o maior numero
dentre eles.
int maior(int *vetor)
Obs: NÃO use a notação de vetor (colchetes) da linguagem C para manipulação dos
elementos do vetor, utilize somente aritmética de ponteiros.
5. [PONTEIRO COM STRUCT] Escreva um programa em C que leia duas datas (dia, mes e
ano) e calcule a diferença de dias entre as duas datas.
Utilize um tipo de dado heterogeneo (struct) para representar a data.
O calculo da diferença de dias entre as datas deve ser implementado como uma funçao.
int diferencaDias(struct Data *data1, struct Data *data2)
Pagina2
6. [PONTEIRO COM STRUCT] Escreva um programa em C que define uma struct para
representar um ponto cartesiano (x, y), leia dois pontos e calcule a distancia entre os
pontos.
O calculo da distancia entre os dois pontos deve ser implementado como uma funçao.
Utilize um tipo de dado heterogeneo (struct) para representar o ponto cartesiano
(ponto2D).
float distancia(struct Ponto2D *ponto1, struct Ponto2D *ponto2)
