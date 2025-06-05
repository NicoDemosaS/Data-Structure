#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Grafo.h"
#include "../Cap3/Utils.h"

int comparaVertice(void *info1, void *info2)
{

    pVertice v1 = (pVertice)info1;
    pVertice v2 = (pVertice)info2;

    int *id1 = (int *)v1->info;
    int *id2 = (int *)v2->info;

    return *id2 - *id1;
}

/* ----------------------------- */
void imprimeAdjacencia(void *info1)
{
    pVertice v = (pVertice)info1;
    printf("%d - ", *((int *)(v->info)));
}

/* ----------------------------- */
void imprimeVertice(void *info1)
{
    pVertice v = (pVertice)info1;
    printf("\nVertice %d - Adjacencias [", *((int *)v->info));

    imprimirLista(v->listaAdjacencias, imprimeAdjacencia);
    printf("]\n");
}

/* ----------------------------- */
void imprimeVerticeSemAdjacencias(void *info1)
{
    pVertice v = (pVertice)info1;
    printf("\nVertice %d - ", *((int *)v->info));
}

/* ---------------------------------------- */
void *alocaInfoVertice(void *info)
{
    pVertice pv = (pVertice)malloc(sizeof(Vertice));
    pv->info = alocaInfoInt(((pVertice)info)->info);
    return pv;
}

/* ----------------------------- */
void main()
{

    int vertices[] = {1, 2, 3, 4, 5};

    int opcao, vOrigem, vDestino;
    int *pv;

    pDGrafo grafo = criarGrafoPlus(comparaVertice, imprimeVertice, alocaInfoVertice);

    do
    {
        printf("\n0  - Criar grafo \n");
        printf("  1  - Incluir Vertice \n");
        printf("  2  - Incluir Aresta \n");
        printf("  3  - Excluir Vertice \n");
        printf("  4  - Excluir Aresta \n");
        printf("  5  - Mostrar grafo \n");
        printf("  6  - Busca em profundidade \n");
        printf("  7  - Busca em amplitude \n");
        printf("  8  - Existe caminho (entre dois vertices) \n");
        printf("  9  - Encontra caminho (entre dois vertices) \n");
        printf(" 10 - Verificar se existe um caminho Euleriano\n");
        printf(" 11 - Verificar se existe um caminho Hamiltoniano \n");
        printf(" 12 - Sair \n");

        scanf("%d", &opcao);

        switch (opcao)
        {

        case 0:
            incluirVertice(grafo, &vertices[0], NULL);
            incluirVertice(grafo, &vertices[1], NULL);
            incluirVertice(grafo, &vertices[2], NULL);
            incluirVertice(grafo, &vertices[3], NULL);
            incluirVertice(grafo, &vertices[4], NULL);

            incluirAresta(grafo, &vertices[0], &vertices[1], NULL);
            incluirAresta(grafo, &vertices[1], &vertices[3], NULL);
            incluirAresta(grafo, &vertices[2], &vertices[3], NULL);
            incluirAresta(grafo, &vertices[2], &vertices[4], NULL);
            incluirAresta(grafo, &vertices[3], &vertices[4], NULL);
            incluirAresta(grafo, &vertices[4], &vertices[1], NULL);

            mostrarGrafo(grafo, NULL);
            getchar();

            break;

        case 1:

            pv = (int *)malloc(sizeof(int));
            printf("ID do v�rtice : ");
            scanf("%d", pv);
            incluirVertice(grafo, pv, NULL);

            mostrarGrafo(grafo, NULL);
            getchar();

            break;

        case 2:

            printf("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);
            incluirAresta(grafo, &vOrigem, &vDestino, NULL);

            mostrarGrafo(grafo, NULL);
            getchar();

            break;

        case 3:

            printf("\nExclusão do vertíce com ID igual: ");
            scanf("%d", &vOrigem);
            excluirVertice(grafo, vOrigem, comparaInt);
            getchar();

            break;

        case 4:

            printf("\nExclusão da Aresta com ID de vertice de origem igual: ");
            scanf("%d", &vOrigem);
            printf("\n E ID de vertice de destino igual: ");
            scanf("%d", &vDestino);

            excluirAresta(grafo, vOrigem, vDestino, comparaInt);
            getchar();

            break;

        case 5:

            mostrarGrafo(grafo, NULL);
            getchar();
            break;

        case 6:

            buscaEmProfundidade(grafo, NULL, imprimeVerticeSemAdjacencias);
            getchar();
            break;

        case 7:

            buscaAmplitude(grafo, comparaInt, imprimeInt);
            getchar();

            break;

        case 8:

            printf("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);

            int result = existeCaminho(grafo, &vOrigem, &vDestino);
            // existe um caminho
            if (result != 0)
                printf("Existe caminho!");
            else
                printf("N�o existe caminho!");

            getchar();
            break;

        case 9:

            printf("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);

            pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino);
            if (caminho->quantidade > 0)
            {
                printf("\n Existe um caminho: ");
                imprimirLista(caminho, imprimeVerticeSemAdjacencias);
            }
            else
                printf("\n *** N�O existe um caminho. *** ");

            getchar();

            break;

        case 10:

            int caminhoEuleriano = existeCaminhoEuleriano(grafo);

            if (caminhoEuleriano == 1)
            {
                printf("\nExiste um caminho euleriano neste grafo\n");
            }
            else
            {
                printf("\nNão existe um caminho euleriano neste grafo\n");
            }

            break;

        case 11:

            int caminhoHamaltoniano = existeCaminhoHamiltoniano(grafo);

            if (caminhoHamaltoniano == 1)
            {
                printf("\nExiste um caminho Hamiltoniano neste grafo\n");
            }
            else
            {
                printf("\nNão existe um caminho Hamiltoniano neste grafo\n");
            }

            break;
        }

    } while (opcao != 12);
}
