#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

/*programa que implementa arvores 2-3 com chaves inteiras*/

int main()
{
    arvore23_t *t;
    int i,N,chave;
    char comando[9];

    /* Cria árvore 2-3 */
    t = arvore23_aloca();
    
    /*le quantidade de entradas*/
    scanf("%d\n",&N);
    for(i = 0; i < N; i++) {
        /*le instrução*/
	scanf("%s", comando);
	if (!strcmp(comando,"inserir")){
		scanf("%d", &chave);
 		arvore23_insere(&t, chave);
	}
	if (!strcmp(comando,"buscar")){
		scanf("%d", &chave);
 		if (!arvore23_busca(t, chave))
			printf(":(\n");
		else
			printf(":)\n");		
	}
	if (!strcmp(comando,"imprimir")){
		arvore23_imprime(t);
		printf("\n");
	}
    } 
    /* libera memória */
    arvore23_libera(t);

    return 0;
}
