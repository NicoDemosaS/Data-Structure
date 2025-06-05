#ifndef EXISTE_CAMINHO_EULERIANO_H
#define EXISTE_CAMINHO_EULERIANO_H

// Função para verificar a existência de um caminho euleriano no grafo
int existeCaminhoEuleriano(pDGrafo grafo) {
    int numVertices = grafo->listaVertices;

    // Verifica se o grafo é conectado
    if (!verificarConectividade(grafo)) {
        return 0; // Grafo não conectado, não há caminho euleriano
    }

    // Verifica se todos os vértices têm grau par
    for (int v = 0; v < numVertices; v++) {
        if (grafo->grau[v] % 2 != 0) {
            return 0; // Grafo contém vértice com grau ímpar, não há caminho euleriano
        }
    }

    return 1; // Grafo possui um caminho euleriano
}

// Função para verificar se o grafo é conectado
int verificarConectividade(pDGrafo grafo) {
    int numVertices = grafo->listaVertices;
    int visitados[numVertices];
    for (int v = 0; v < numVertices; v++) {
        visitados[v] = 0; // Inicializa todos os vértices como não visitados
    }

    // Inicia a busca em profundidade a partir do primeiro vértice
    buscaProfundidade(grafo, 0, visitados);

    // Verifica se todos os vértices foram visitados
    for (int v = 0; v < numVertices; v++) {
        if (!visitados[v]) {
            return 0; // Grafo não conectado
        }
    }

    return 1; // Grafo conectado
}

// Função de busca em profundidade para verificar a conectividade do grafo
void buscaProfundidade(pDGrafo grafo, int vertice, int visitados[]) {
    visitados[vertice] = 1; // Marca o vértice como visitado

    // Percorre todos os vértices adjacentes não visitados
    for (int i = 0; i < grafo->grau[vertice]; i++) {
        int adjacente = grafo->listaAdjacencias[vertice][i];
        if (!visitados[adjacente]) {
            buscaProfundidade(grafo, adjacente, visitados);
        }
    }
}

#endif
