#include <stdio.h>
#include <stdlib.h>

/* ----------------------------- */
struct Pessoa{
   int          cpf;
   char         nome[30];
   int          idade;
};

/* ----------------------------- */
void main(){
   FILE* arqPessoa;

   struct Pessoa p;

   arqPessoa = fopen("Pessoas.dat", "r+b");
   if (arqPessoa == NULL){
      arqPessoa = fopen("Pessoas.dat", "w+b");
   }

   scanf("%d", &p.cpf);
   fflush(stdin);
   gets (p.nome);
   fflush(stdin);
   scanf("%d", &p.idade);
   fflush(stdin);

   fseek(arqPessoa, 0, SEEK_END);
   fwrite(&p, sizeof(struct Pessoa), 1, arqPessoa);

   rewind(arqPessoa);

   while(fread(&p, sizeof(struct Pessoa), 1, arqPessoa) != 0){

       printf("\n �pf: %d - Nome: %s - Idade: %d",
              p.cpf, p.nome, p.idade);
   }

   fclose(arqPessoa);
}

