#ifndef OPEN_H
#define OPEN_H

pDFile  abrir(const char* arquivo, int tamanho){

    pDFile pdf = (pDFile) malloc(sizeof(struct dFile));

    pdf->arquivo = fopen(arquivo, "r+b");
    if(pdf->arquivo == NULL)
        pdf->arquivo = fopen(arquivo, "w+b");

    pdf->tamanhoRegistro = tamanho;

    return pdf;
}


#endif
