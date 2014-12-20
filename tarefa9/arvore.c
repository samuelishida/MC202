#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

/* árvore.c - falta implementar funções arvore23_insere e arvore23_busca*/
/* Cuidado ao alterar funções já implementadas*/

/* arvore23_aloca() - Cria árvore 2-3. */
arvore23_t *arvore23_aloca()
{
    return NULL;
}

/* arvore23_libera() - Libera árvore 2-3. */
void arvore23_libera(arvore23_t *t)
{
    if(t!=NULL){
		arvore23_libera(t->filho1);
		arvore23_libera(t->filho2);
		arvore23_libera(t->filho3);
		free(t); t=NULL;
    }
}

void arvore23_insere(arvore23_t **t, int chave)
{
    if(*t==NULL)/*se t for vazia*/{
    	(*t) = (arvore23_t *) malloc(sizeof(arvore23_t));
    	(*t)->nchaves = 1;
		(*t)->chave1 = chave;
    	(*t)->pai = (*t)->filho1 = (*t)->filho2 = (*t)->filho3 = NULL;
		return;
    }
    if (arvore23_busca((*t), chave)) /*se chave ja existe em árvore*/ 
		return;


    // Test that (*t) is 0, which suggests the root, or if it truly is a leaf.
    if ((*t) == 0 || !(*t)->isLeafNode()) {

        Node23<K> *leaf;
        bool bRc = DoSearch(key, root, leaf);
        arovre23_insere(key, leaf);
		return
    }

    // If the leaf node is a two node, arovre23_insere the key, and we are done.
    if (!(*t)->isThreeNode()) {

        if (key > (*t)->smallValue) {

            (*t)->largeValue = key;
            (*t)->setThreeNode(true);

        } else if (key < (*t)->smallValue) {

            (*t)->largeValue = (*t)->smallValue;
            (*t)->smallValue = key;
            (*t)->setThreeNode(true);

        } else {
           return ;
        }

    } else {

        // ... else it is a three node and cannot contain three items, so split it into two two-nodes.
        Split((*t), key);
    }

    return ;

}

int arvore23_busca(arvore23_t *t, int chave)
{

/*-------------------------------
Completar aqui
---------------------------------*/

    return 0;
}

void arvore23_imprime(arvore23_t *t){
    if(t!=NULL){
	printf("( ");
    	if (t->nchaves == 1){
		arvore23_imprime(t->filho1);
		printf("%d ",t->chave1);
		arvore23_imprime(t->filho2);
   	}
    	else /*t->nchaves == 2*/{
		arvore23_imprime(t->filho1);
		printf("%d ",t->chave1);
		arvore23_imprime(t->filho2);
		printf("%d ",t->chave2);
		arvore23_imprime(t->filho3);
	}
	printf(") ");
    }
}

