#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>  // Para strcspn
#include "BibliotecaListas/Lista.h"
#include "Utils.h"
#include "Persistencia.h"

struct Pessoa{
   int          cpf;
   char         nome[30];
   int          idade;
};

//---------------------------------------------
int comparaChavePessoa(void *info1, void *info2){
  int           *chave = (int *) info1;
  struct Pessoa *p     = (struct Pessoa*) info2;

  return *chave - p->cpf;
}

//---------------------------------------------
void imprimePessoa(void *dados){

    struct Pessoa *pp = (struct Pessoa *) dados;
    printf("CPF: %d -  Idade: %d - Nome: %s  \n", pp->cpf, pp->idade, pp->nome);
}

void limparBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};

// -------------------------------------------
// -------------------------------------------
void main(){

  struct Pessoa  pessoa;
  int cpf;
  pDFile arqPes;

  int op;




  do{
    // system("cls") // Limpar a tela Windows
    system("clear"); // Limpa a tela (Linux)
    printf("1 - Cadastrar pessoa \n");
    printf("2 - Listar pessoas \n");
    printf("3 - Alterar dados de uma pessoa \n");
    printf("4 - Excluir pessoa \n");
    printf("    ---------------------------------------------- \n");
    printf("9 - Sair \n");

    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    // fflush(stdin);
    limparBuffer();
    
    pDLista pessoas;


    switch (op){      
    
      case 1 :
              printf("CPF: ");
              scanf("%d", &pessoa.cpf);
              // fflush(stdin);
              limparBuffer(); // Para funcionar no LINUX
              printf("NOME: ");
              fgets(pessoa.nome, sizeof(pessoa.nome), stdin); // Fgets ja consome o \n
              // fflush(stdin);
              printf("IDADE: ");
              scanf("%d", &pessoa.idade);
              // fflush(stdin);
              limparBuffer();

              arqPes = abrir("Pessoas.dat", sizeof(struct Pessoa));
              createe(arqPes, &pessoa);
              close(arqPes);
              

              printf("Pessoa cadastrada com sucesso!\n");
              printf("Pressione Enter para continuar...");
              getchar();
              break;
      case 2 :               
              arqPes = abrir("Pessoas.dat", sizeof(struct Pessoa));
              pessoas = queryAll(arqPes);
              imprimirLista(pessoas, imprimePessoa);
              close(arqPes);
              printf("\nPressione Enter para continuar...");
              getchar();
              break;    
      case 3 :
              printf("CPF: ");
              scanf("%d", &pessoa.cpf);
              // fflush(stdin);
              limparBuffer();
              printf("NOME: ");
              fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
              // fflush(stdin);
              // limparBuffer();
              printf("IDADE: ");
              scanf("%d", &pessoa.idade);
              // fflush(stdin); 
              limparBuffer();            
              
              arqPes = abrir("Pessoas.dat", sizeof(struct Pessoa));
              pessoas = queryAll(arqPes);
              update(arqPes, &pessoa.cpf, &pessoa, comparaChavePessoa);
              close(arqPes);
              break;

      case 4 :
              arqPes = abrir("Pessoas.dat", sizeof(struct Pessoa));
              int cpf;
              printf("CPF para Excluir: ");
              scanf("%d", &cpf);
              deletee(arqPes, &cpf, comparaChavePessoa);
              
              close(arqPes);
              break;


      case 5 :
      
   }

  } while(op != 9);






}
