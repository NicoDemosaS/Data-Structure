#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

/* --------------------------- */
void excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc)
{
    if (fc == NULL)
        fc = grafo->fc;

    if (grafo == NULL || vOrig == NULL || vDest == NULL)
    {
        return;
    }

    pVertice origem = buscarVertice(grafo, vOrig, fc);
    pVertice destino = buscarVertice(grafo, vDest, fc);

    if (origem != NULL && destino != NULL)
    {
        excluirInfo(origem->listaAdjacencias, vDest, fc);
    }
}

#endif
