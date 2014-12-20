/* arvore.h - assinatura de funções para implementar árvore 2-3 com chaves inteiras*/

/*arvore23_no_t - define tipo nó de uma arvore 2-3*/
typedef struct arvore23_no {
    int chave1, chave2;					/*valor das chaves do no, se existirem*/
    int nchaves;					/*numero de chaves existentes no nó. (Pode ser 1 ou 2) */
    struct arvore23_no *filho1, *filho2, *filho3;	/*ponteiros para os nós filhos*/
    struct arvore23_no *pai;				/*ponteiro para o nó pai (não é usado na função imprime)*/
} arvore23_t;

/*Novos campos podem ser acrescentados ou retirados da estrutura de dados a gosto.*/
/*Mas cuidado! Excluir um campo pode alterar a corretude da função imprime*/

/* arvore23_aloca() - Cria árvore 2-3. */
arvore23_t *arvore23_aloca();

/* arvore23_libera() - Libera árvore 2-3. */
void arvore23_libera(arvore23_t *t);

/* arvore23_insere() - insere chave na árvore 2-3. Não insere se chave já existir na árvore */
void arvore23_insere(arvore23_t **t, int chave);

/* arvore23_busca() - busca chave na árvore 2-3. Retorna 1 se encontrar ou 0 se não encontrar */
int arvore23_busca(arvore23_t *t, int chave);

/* arvore23_imprime() - imprime árvore 2-3. */
void arvore23_imprime(arvore23_t *t);


