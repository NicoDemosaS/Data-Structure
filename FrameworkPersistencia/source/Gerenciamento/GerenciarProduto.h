#ifndef GERENCIARPRODUTO_H
#define GERENCIARPRODUTO_H
#include <stdlib.h>
#include <stdio.h>

struct Produto{
    int codigo;
    char descricao[30];
    float preco;
};

void imprimeProduto(void *dados){

    struct Produto *pp = (struct Produto *) dados;
    printf("Codigo: %d -  Preco: %.2f - Descricao: %s\n", pp->codigo, pp->preco, pp->descricao);
}

int comparaChaveProduto(void *info1, void *info2){
  int           *chave = (int *) info1;
  struct Produto *p     = (struct Produto*) info2;

  return *chave - p->codigo;
}

struct Produto produto;
pDFile arqProduto;
pDLista produtos;

void GerenciarProduto(){
    
    int op;
    system("clear"); // Limpa a tela (Linux)
    printf("1 - Cadastrar Produto\n");
    printf("2 - Listar Produto \n");
    printf("3 - Alterar Produto \n");
    printf("4 - Excluir Produto \n");
    printf("    ---------------------------------------------- \n");
    printf("9 - Sair \n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    switch (op){
        case 1: // Cadastrar  Produto
            printf("Codigo: ");
            scanf("%d", &produto.codigo);
            // fflush(stdin);
            limparBuffer(); // Para funcionar no LINUX
            printf("Descricao: ");
            fgets(produto.descricao, sizeof(produto.descricao), stdin); // Fgets ja consome o \n
            // fflush(stdin);
            printf("Preco: ");
            scanf("%f", &produto.preco);
            // fflush(stdin);
            limparBuffer();




            arqProduto = abrir("Produto.dat", sizeof(struct Produto));
            createe(arqProduto, &produto);
            close(arqProduto);
            printf("\nProduto Cadastrado");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;


        case 2: // Listar Produto 
            arqProduto = abrir("Produto.dat", sizeof(struct Produto));
            produtos = queryAll(arqProduto);
            imprimirLista(produtos, imprimeProduto);
            close(arqProduto);
            printf("\nPressione Enter para continuar...");
            limparBuffer(); // Limpa o buffer antes do getchar
            getchar();
            break;

        case 3: // Alterar Produto
            printf("CODIGO: ");
            scanf("%d", &produto.codigo);
            // fflush(stdin);
            limparBuffer();
            printf("Descricao: ");
            fgets(produto.descricao, sizeof(produto.descricao), stdin);
            // fflush(stdin);
            // limparBuffer();
            printf("Preco: ");
            scanf("%f", &produto.preco);
            // fflush(stdin); 
            limparBuffer();            
            
            arqProduto = abrir("Produto.dat", sizeof(struct Produto));
            produtos = queryAll(arqProduto);
            update(arqProduto, &produto.codigo, &produto, comparaChaveProduto);
            close(arqProduto);
            printf("\nProduto Alterado");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;

        case 4: // Excluir Produto
            arqProduto = abrir("Produto.dat", sizeof(struct Produto));
            int codigo;
            printf("CODIGO do Produto para Excluir: ");
            scanf("%d", &codigo);
            limparBuffer(); 
            deletee(arqProduto, &codigo, comparaChaveProduto);
            close(arqProduto);
            
            printf("\nProduto Deletado");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
    }




}


#endif