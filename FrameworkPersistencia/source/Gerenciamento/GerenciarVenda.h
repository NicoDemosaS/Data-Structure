#ifndef GERENCIARVENDA_H
#define GERENCIARVENDA_H
#include <stdlib.h>
#include <stdio.h>



struct Venda{
    int numero;
    struct Data data;
    int CPF;
    int CODIGOPRODUTO;
    int quantidade;
    float precovenda;
    int cancelada;
};
int comparaChaveVenda(void *info1, void *info2){
  int           *chave = (int *) info1;
  struct Venda *p     = (struct Venda*) info2;

  return *chave - p->numero;
}

struct Venda venda;
pDFile arqVenda;
pDLista vendas;

void imprimeVenda(void *dados){
    struct Venda *v = (struct Venda *) dados;

    // printf("Numero: %d - Data: %02d/%02d/%04d - CPF: %d - Produto: %d - Qtd: %d - Preco: %.2f : Cancelamento: %d\n", 
    //        v->numero, v->data.dia, v->data.mes, v->data.ano, 
    //        v->CPF, v->CODIGOPRODUTO, v->quantidade, v->precovenda, v->cancelada);
    // if(v->cancelada == 1){
    //     printf("Cancelada\n");
    // }

    if(v->cancelada == 0){
        printf("Numero: %d - Data: %02d/%02d/%04d - CPF: %d - Produto: %d - Qtd: %d - Preco: %.2f\n", 
           v->numero, v->data.dia, v->data.mes, v->data.ano, 
           v->CPF, v->CODIGOPRODUTO, v->quantidade, v->precovenda);
    }
    if (v->cancelada == 1){
        printf("Numero: %d - Data: %02d/%02d/%04d - CPF: %d - Produto: %d - Qtd: %d - Preco: %.2f CANCELADA!\n", 
           v->numero, v->data.dia, v->data.mes, v->data.ano, 
           v->CPF, v->CODIGOPRODUTO, v->quantidade, v->precovenda);
    }
}

void GerenciarVenda(){
    
    int op;
    system("clear"); // Para Linux
    printf("1 - Cadastrar Venda\n");
    printf("2 - Listar Vendas \n");
    printf("3 - Cancelar Venda \n");
    printf("    ---------------------------------------------- \n");
    printf("9 - Sair \n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    switch (op){
        case 1: // Cadastrar  Venda
            venda.cancelada = 0;

            printf("Numero: ");
            scanf("%d", &venda.numero);
            limparBuffer(); // Para funcionar no LINUX
            
            printf("Data (dia mes ano): ");
            scanf("%d %d %d", &venda.data.dia, &venda.data.mes, &venda.data.ano);
            limparBuffer();

            arqCliente = abrir("Cliente.dat", sizeof(struct Cliente));
            do{  // Teste para verificar se CPF existe em Clientes.
                printf("CPF - 9 Para cancelar.: ");
                scanf("%d", &venda.CPF);
                limparBuffer();
                if(venda.CPF == 9) break;

            }while(retrieve(arqCliente, &venda.CPF, comparaChaveCliente) == NULL);
            close(arqCliente);
            if(venda.CPF == 9) break;

            arqProduto = abrir("Produto.dat", sizeof(struct Produto));
            do{
                printf("Codigo Produto - 9 Para cancelar: ");
                scanf("%d", &venda.CODIGOPRODUTO);
                limparBuffer();
                if(venda.CODIGOPRODUTO == 0) break;


            }while(retrieve(arqProduto, &venda.CODIGOPRODUTO, comparaChaveProduto) == NULL);
            close(arqProduto);
            if(venda.CODIGOPRODUTO == 0) break;
                
            printf("Quantidade: ");
            scanf("%d", &venda.quantidade);
            
            printf("Preco Venda: ");
            scanf("%f", &venda.precovenda); // Talvez esse preco venda tenha de pegar preco do produto e multiplicar pela quantidade que foi registrada agora, preco final da venda.
            limparBuffer();

        


            arqVenda = abrir("Venda.dat", sizeof(struct Venda));
            createe(arqVenda, &venda);
            close(arqVenda);
            printf("\nVenda Cadastrada");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;

        case 2: // Listar Vendas
            arqVenda = abrir("Venda.dat", sizeof(struct Venda));
            vendas = queryAll(arqVenda);
            imprimirLista(vendas, imprimeVenda);
            close(arqVenda);
            printf("\nPressione Enter para continuar...");
            limparBuffer(); // Limpa o buffer antes do getchar
            getchar();
            break;

        case 3: // Cancelar Venda <nao excluir colocar cancelada>
            printf("CODIGO: ");
            scanf("%d", &venda.numero);
            // fflush(stdin);
            limparBuffer();
            venda.cancelada = 1;
            arqVenda = abrir("Venda.dat", sizeof(struct Venda));
            vendas = queryAll(arqVenda);
            update(arqVenda, &venda.numero, &venda, comparaChaveVenda);
            close(arqVenda);
            printf("\nVenda Cancelada");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
    }




}


#endif