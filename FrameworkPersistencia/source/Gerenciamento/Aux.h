#ifndef AUX_H
#define AUX_H
#include <stdlib.h>
#include <stdio.h>


void limparBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};

#endif