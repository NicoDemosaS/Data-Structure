/* --------------------------
   Tipos de dados
   -------------------------- */
typedef struct dFile DFile;
typedef DFile*       pDFile;

typedef int   (*FuncaoComparacao) (void *, void *);
typedef void* (*FuncaoAloca)      ();
typedef void  (*FuncaoImpressao)  (void *);
typedef int   (*FuncaoPredicado)  (void *);

// Uma fun��o de predicato estendida recebe os dados e um seletor para avaliar
// o predicado.
// Por exemplo, quando aplicado ao cadastro de pessoa, pode-se filtrar as
// pessoas que fazem anivers�rio em um determinado m�s, sendo que o
// primeiro par�metro s�o os dados da pessoa e o segundo par�metro � o m�s.
typedef int   (*FuncaoPredicadoExt)  (void*, void*);

// Toda fun��o de atualiza��o precisa definir dois par�metros:
//   1) o primeiro deles � os dados a serem atualizados (em geral a struct), e
//   2) o segundo par�metro � o valor que ser� utilizado para atualizar
// A fun��o deve retornar os dados (da struct) atualizados.
typedef void* (*FuncaoAtualizacao)(void *, void *);

/* --------------------------
   Opera��es CRUD
   -------------------------- */
pDFile  abrir     (const char*, int);
void    createe   (pDFile, void*);                          // dados
void*   retrieve  (pDFile, void*, FuncaoComparacao);        // chave
void    update    (pDFile, void*, void*, FuncaoComparacao); // chave e os dados
void    deletee   (pDFile, void*, FuncaoComparacao);        // chave
void    close     (pDFile);

pDLista queryAll  (pDFile);
pDLista queryBy   (pDFile, FuncaoPredicado);

void    persistAll (pDFile, pDLista);




