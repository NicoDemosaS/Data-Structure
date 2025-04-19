// ----------------------------------------------------------
// ---- Defini��o dos tipos de dado -------------------------
// ----------------------------------------------------------
struct CartaBaralho {
   char naipe;
   int  valor;
};

// ----------------------------------------------------------
// ---- Defini��o dos tipos de ponteiros para fun��o---------
// ----------------------------------------------------------
typedef  int   (*FuncaoComparacao)   (void *, void *);
typedef  int   (*FuncaoPredicado)    (void *);
typedef  float (*FuncaoMapeamento)   (void *);
typedef  void  (*FuncaoOperacao)     (void *);
typedef  int   (*FuncaoCoringa)      (struct CartaBaralho, struct CartaBaralho);

// ----------------------------------------------------------
// --------- Assinaturas das fun��es ------------------------
// ----------------------------------------------------------

//-------------------------------------------
/* a fun��o bubbleSort � aquela mesma discutida em aula, est� pronta */
void bubbleSort(void* [], int, FuncaoComparacao);

//-------------------------------------------
/* o objetivo da fun��o "encontrarMaior" � retornar o maior valor contido no vetor
*/
void* encontrarMaior(void* [], int, FuncaoComparacao);

//-------------------------------------------
/* o objetivo da fun��o "contar" � contabilizar a quantidade de elementos do
   vetor que atendem � um determinado predicado
*/
int contar(void* [], int, FuncaoPredicado);

//-------------------------------------------
/* o objetivo da fun��o "calcularMedia" � contabilizar a m�dia das informa��es do
   vetor. Observe que o vetor contem (ponteiros para) qualquer tipo de dado, mas o
   c�lculo da m�dia precisa ser realizado com valores num�ricos.
   Essa incompatibilidade � resolvida com a fun��o de mapeamento, a qual mapeia
   o ponteiro sem tipo (void *) para um valor real de acordo com o contexto de uso
   da fun��o de c�lculo da m�dia.
*/
float calcularMedia(void* [], int, FuncaoMapeamento);

//-------------------------------------------
/* o objetivo da fun��o "aplicarOperacao" � executar uma opera��o em cada elemento do
   vetor, alterando seu conte�do conforme a opera��o aplicada.
*/
void aplicarOperacao(void* [], int, FuncaoOperacao);

//-------------------------------------------
/* o objetivo da fun��o "identificarCoringa" � realizar o processamento das
   cartas do baralho com o objetivo de identificar qual � o coringa considerando
   a carta "vira".
*/
void identificarCoringa(struct CartaBaralho[], int, struct CartaBaralho, FuncaoCoringa);



// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------
// --------- implementa��o das fun��es descritas acima-------
// ----------------------------------------------------------
// ----------------------------------------------------------
// ----------------------------------------------------------

void bubbleSort(void* dados[], int tam, FuncaoComparacao pfc) {

    int   res, i, j, r;
    void  *temp;

    for (i=0; i<tam-1; i++){
       /*printf("Iteracao %d \n", i+1);*/
       for (j=0; j<tam-(i+1); j++){
         /* invocacao da funcao de comparacao por meio do ponteiro para funcao*/
         r = pfc(dados[j],dados[j+1]);
         if (r<0){
            temp       = dados[j];
            dados[j]   = dados[j+1];
            dados[j+1] = temp;
         }
       }
    }
}

//---------------------------------------------------------------
void* encontrarMaior(void* dados[], int tam, FuncaoComparacao pfc){
   void *maior;
   maior = dados[0];
   int i;
   for(i=0;i<tam;i++){
      if(pfc(dados[i], maior) > 0)
         maior = dados[i];
   }

   return maior;
}

//---------------------------------------------------------------
int contar(void* dados[], int tam, FuncaoPredicado pfp){
   int cont = 0;
   int i = 0;
   for(i=0;i<tam;i++){
      if(pfp(dados[i]) == 1){
         cont++;
      }
   }
   return cont;
}

//---------------------------------------------------------------
float calcularMedia(void* dados[], int tam, FuncaoMapeamento pfm){
   int i = 0;
   float soma = 0;
   for(i=0;i<tam;i++){
         soma += pfm(dados[i]);
   }
   if(tam > 0){
      return soma/tam;
   }
   else
      return 0.0f;
}

//---------------------------------------------------------------
void aplicarOperacao(void* dados[], int tam, FuncaoOperacao pfo){
   int i = 0;
   for(i=0;i<tam;i++){
      pfo(dados[i]);
   }
}

//---------------------------------------------------------------
void identificarCoringa(struct CartaBaralho baralho[], int tam,
                        struct CartaBaralho vira, FuncaoCoringa pfm){
      int i;
      for(i=0;i<52;i++){
         //printf("Verificando carta -> Valor: %d, Naipe: %c\n", baralho[i].valor, baralho[i].naipe);
      if(pfm(baralho[i], vira) == 1){
                           printf("\nCoringa Encontrado -> Valor %d, Naipe %c", baralho[i].valor, baralho[i].naipe);
                           return; 
                        }                 
                        } 
      printf("nao encontrado o coringa");
      

}
