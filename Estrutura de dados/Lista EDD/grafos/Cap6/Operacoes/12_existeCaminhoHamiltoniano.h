#ifndef EXISTE_CAMINHO_HAMILTONIANO_H
#define EXISTE_CAMINHO_HAMILTONIANO_H

// Função para verificar se um caminho Hamiltoniano existe no grafo
int existeCaminhoHamiltoniano(pDGrafo grafo) {
    int numVertices = grafo->listaVertices;

    // Cria um vetor para armazenar o caminho
    int caminho[numVertices];
    for (int i = 0; i < numVertices; i++) {
        caminho[i] = -1; // Inicializa o caminho com valores inválidos
    }

    // Define o primeiro vértice do caminho
    caminho[0] = 0;

    // Chama a função recursiva para verificar o caminho Hamiltoniano
    if (verificarCaminhoHamiltoniano(grafo, caminho, 1)) {
        return 1; // Caminho Hamiltoniano encontrado
    }

    return 0; // Caminho Hamiltoniano não encontrado
}

// Função recursiva para verificar o caminho Hamiltoniano
int verificarCaminhoHamiltoniano(pDGrafo  grafo, int caminho[], int posicao) {
    int numVertices = grafo->listaVertices;

    // Caso base: todos os vértices foram visitados
    if (posicao == numVertices) {
        // Verifica se o último vértice possui uma aresta de volta para o primeiro vértice
        int ultimoVertice = caminho[posicao - 1];
        int primeiroVertice = caminho[0];
        if (existeAresta(grafo, ultimoVertice, primeiroVertice)) {
            return 1; // Caminho Hamiltoniano encontrado
        } else {
            return 0; // Caminho Hamiltoniano não encontrado
        }
    }

    // Tenta adicionar vértices adicionais ao caminho
    for (int v = 1; v < numVertices; v++) {
        // Verifica se o vértice pode ser adicionado ao caminho
        if (ehValido(grafo, v, caminho, posicao)) {
            caminho[posicao] = v; // Adiciona o vértice ao caminho

            // Verifica recursivamente se o caminho pode ser continuado
            if (verificarCaminhoHamiltoniano(grafo, caminho, posicao + 1)) {
                return 1; // Caminho Hamiltoniano encontrado
            }

            caminho[posicao] = -1; // Remove o vértice do caminho
        }
    }

    return 0; // Caminho Hamiltoniano não encontrado
}

// Função auxiliar para verificar se um vértice pode ser adicionado ao caminho
int ehValido(pDGrafo grafo, int vertice, int caminho[], int posicao) {
    // Verifica se o vértice já foi visitado anteriormente
    if (caminho[posicao - 1] == vertice) {
        return 0;
    }

    // Verifica se há uma aresta entre o vértice anterior e o vértice atual
    int ultimoVertice = caminho[posicao - 1];
    if (!existeAresta(grafo, ultimoVertice, vertice)) {
        return 0;
    }

    // Verifica se o vértice já foi visitado anteriormente no caminho atual
    for (int i = 0; i < posicao; i++) {
        if (caminho[i] == vertice) {
            return 0;
        }
    }

    return 1;
}

#endif
