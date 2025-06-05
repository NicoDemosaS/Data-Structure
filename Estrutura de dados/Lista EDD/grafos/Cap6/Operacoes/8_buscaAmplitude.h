#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H


// Função para realizar a busca em amplitude
void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi) {
    if (grafo == NULL)
        return;

    if (fc == NULL)
        fc = grafo->fc;

    if (fi == NULL)
        fi = grafo->fi;

    pDLista fila = criarLista(); // Fila para armazenar os vértices a serem visitados
    pDLista visitados = criarLista(); // Lista para armazenar os vértices já visitados

    pNoh atual = grafo->listaVertices->primeiro; // Começa a busca a partir do primeiro vértice do grafo

    // Adiciona o primeiro vértice à fila
    inserirInfo(fila, atual->info);

    while (!listaVazia(fila)) {
        // Remove o vértice da frente da fila
        void *vertice = removerInicio(fila);

        // Verifica se o vértice já foi visitado
        if (!contemInfo(visitados, vertice, fc)) {
            // Marca o vértice como visitado
            inserirInfo(visitados, vertice);

            // Realiza a impressão do vértice
            fi(vertice);

            // Percorre as adjacências do vértice
            pNoh adjacente = ((pVertice)vertice)->listaAdjacencias->primeiro;
            while (adjacente != NULL) {
                // Obtém o vértice adjacente
                void *adjacenteInfo = adjacente->info;

                // Verifica se o vértice adjacente já foi visitado
                if (!contemInfo(visitados, adjacenteInfo, fc)) {
                    // Adiciona o vértice adjacente à fila para visitar posteriormente
                    inserirInfo(fila, adjacenteInfo);
                }

                // Avança para a próxima adjacência
                adjacente = adjacente->prox;
            }
        }
    }

    // Libera a memória utilizada pela fila e pela lista de visitados
    destruirLista(fila);
    destruirLista(visitados);
}

#endif
