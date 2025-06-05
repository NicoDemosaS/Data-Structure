#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H

/* --------------------------- */
void excluirVertice(pDGrafo grafo, void *info, FuncaoComparacao fc)
{
    if (fc == NULL)
        fc = grafo->fc;

    if (grafo == NULL)
    {
        return;
    }

    pVertice  vertice = buscarVertice(grafo, info, fc);
    if (vertice != NULL)
    {
        excluirInfo(grafo->listaVertices, vertice, fc);
    }
}
#endif
