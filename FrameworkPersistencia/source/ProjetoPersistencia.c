#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>  // Para strcspn
#include "../Persistencia/BibliotecaListas/Lista.h"
#include "../Persistencia/Utils.h"
#include "../Persistencia/Persistencia.h"
#include "Gerenciamento/GerenciarCliente.h"
#include "Gerenciamento/GerenciarProduto.h"
#include "Gerenciamento/GerenciarVenda.h"


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
    printf("1 - Gerenciar Vendas \n");
    printf("2 - Gerenciar Produto \n");
    printf("3 - Gerenciar Cliente \n");
    printf("    ---------------------------------------------- \n");
    printf("9 - Sair \n");

    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    // fflush(stdin);
    limparBuffer();
    
    pDLista pessoas;


    switch (op){      
    
      case 1 : // Gerenciar Vendas

              GerenciarVenda(); /// Chama a funcao para as opcoes de GerenciarVenda
              // printf("CPF: ");
              // scanf("%d", &pessoa.cpf);
              // // fflush(stdin);
              // limparBuffer(); // Para funcionar no LINUX
              // printf("NOME: ");
              // fgets(pessoa.nome, sizeof(pessoa.nome), stdin); // Fgets ja consome o \n
              // // fflush(stdin);
              // printf("IDADE: ");
              // scanf("%d", &pessoa.idade);
              // // fflush(stdin);
              // limparBuffer();

              // arqPes = abrir("Pessoas.dat", sizeof(struct Pessoa));
              // createe(arqPes, &pessoa);
              // close(arqPes);
              

              // printf("Pessoa cadastrada com sucesso!\n");
              // printf("Pressione Enter para continuar...");
              // getchar();
              break;
      case 2 :  // Gerenciar Produto
              GerenciarProduto();
              break;    
      case 3 : // Gerenciar Cliente


              GerenciarCliente();
              break;
   }

  } while(op != 9);






}
