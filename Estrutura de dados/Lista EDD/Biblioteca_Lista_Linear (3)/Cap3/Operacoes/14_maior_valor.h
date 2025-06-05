#ifndef MAIOR_VALOR_H
#define MAIOR_VALOR_H

//PROVA PROVA PROVA PROVA

void* maiorInfoRecursiva (pNoh noh, void* maiorAtual, FuncaoComparacao fc)
{

    if (noh == NULL)
    {
        return maiorAtual;
    }
    else
    {
        if( fc(noh->info, maiorAtual)<=0)
        {
            maiorAtual = noh->info;
        } 
        maiorInfoRecursiva(noh->prox, maiorAtual, fc);
    }
}

#endif