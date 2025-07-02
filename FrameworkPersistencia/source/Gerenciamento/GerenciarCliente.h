#ifndef GERENCIARCLIENTE_H
#define GERENCIARCLIENTE_H
#include <stdlib.h>
#include <stdio.h>
#include "Aux.h"

struct Cliente {
    int cpf;
    char nome[30];
    float LimiteCredito;
};

void imprimeCliente(void *dados){

    struct Cliente *pp = (struct Cliente *) dados;
    printf("CPF: %d -  LimiteCredito: %.2f - Nome: %s\n", pp->cpf, pp->LimiteCredito, pp->nome);
}

int comparaChaveCliente(void *info1, void *info2){
  int           *chave = (int *) info1;
  struct Cliente *p     = (struct Cliente*) info2;

  return *chave - p->cpf;
}

pDFile arqCliente;

void GerenciarCliente(){
    struct Cliente cliente;
    pDLista clientes;
    int op;
    system("clear"); // Limpa a tela (Linux)
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Listar Cliente \n");
    printf("3 - Alterar Cliente \n");
    printf("4 - Excluir Cliente \n");
    printf("    ---------------------------------------------- \n");
    printf("9 - Sair \n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    switch (op){
        case 1: // Cadastrar  Cliente
            printf("CPF: ");
            scanf("%d", &cliente.cpf);
            // fflush(stdin);
            limparBuffer(); // Para funcionar no LINUX
            printf("NOME: ");
            fgets(cliente.nome, sizeof(cliente.nome), stdin); // Fgets ja consome o \n
            // fflush(stdin);
            printf("LimiteCredito: ");  // Vou ter de criar uma struct Cliente?
            scanf("%f", &cliente.LimiteCredito);
            // fflush(stdin);
            limparBuffer();

            arqCliente = abrir("Cliente.dat", sizeof(struct Cliente));
            createe(arqCliente, &cliente);
            close(arqCliente);
            printf("\nCliente Cadastrado");
            printf("\nPressione Enter para continuar...");
            limparBuffer();
            getchar();
            break;

        case 2: // Listar Cliente 
            arqCliente = abrir("Cliente.dat", sizeof(struct Cliente));
            clientes = queryAll(arqCliente);
            imprimirLista(clientes, imprimeCliente);
            close(arqCliente);
            printf("\nPressione Enter para continuar...");
            limparBuffer(); // Limpa o buffer antes do getchar
            getchar();
            break;

        case 3: // Alterar Cliente
            printf("CPF: ");
            scanf("%d", &cliente.cpf);
            // fflush(stdin);
            limparBuffer();
            printf("NOME: ");
            fgets(cliente.nome, sizeof(cliente.nome), stdin);
            // fflush(stdin);
            // limparBuffer();
            printf("Limite de Credito: ");
            scanf("%f", &cliente.LimiteCredito);
            // fflush(stdin); 
            limparBuffer();            
            
            arqCliente = abrir("Cliente.dat", sizeof(struct Cliente));
            clientes = queryAll(arqCliente);
            update(arqCliente, &cliente.cpf, &cliente, comparaChaveCliente);
            close(arqCliente);
            printf("\nCliente Alterado");
            printf("\nPressione Enter para continuar...");
            limparBuffer();
            getchar();
            break;

        case 4: // Excluir Cliente
            arqCliente = abrir("Cliente.dat", sizeof(struct Cliente));
            int cpf;
            printf("CPF para Excluir: ");
            scanf("%d", &cpf);
            limparBuffer(); 
            deletee(arqCliente, &cpf, comparaChaveCliente);
            printf("\nCliente Deletado");
            printf("\nPressione Enter para continuar...");
            getchar();
            close(arqCliente);
            break;

    }




}


#endif