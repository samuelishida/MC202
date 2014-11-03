/*
	Tarefa 6 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
	int n;
	struct No *esq, *dir ;
} ArvBin, NoArvBin;

void criaNo (ArvBin **p, int x);

ArvBin *criaArv (int x, ArvBin *NoEsq, ArvBin *NoDir);

void PosOrdem (ArvBin *p);

void free_arv (ArvBin **p);

ArvBin *criaArv (int x, ArvBin *NoEsq, ArvBin *NoDir) {
	ArvBin *p = (ArvBin *)malloc(sizeof(ArvBin)) ;
	p->n = x ;
	p->esq = NoEsq ;
	p->dir = NoDir ;
	return p ;
}

void PosOrdem (ArvBin *p) {
	if (p != NULL) {
		PosOrdem (p->esq) ;
		PosOrdem (p->dir) ;
		printf ("%d", p->n) ;	
	}
}

void free_arv (ArvBin **p) {
	if( (*p)->esq != NULL){
		free_arv (&((*p)->esq)) ;
	}
	if( (*p)->dir != NULL){
		free_arv (&((*p)->dir)) ;
	}
	free(p);
	*p = NULL;
}

void *montaArv (ArvBin **arv, char *preOrdem, char *inOrdem) {
	char preOrdem1[53], preOrdem2[53], inOrdem1[53], inOrdem2[53];
	int i, j;
	
	arv = criaArv(preOrdem[0],NULL,NULL);
	
	for( i=0 ; inOrdem[i] != preOrdem[0]; i++){
		inOrdem1[i] = inOrdem[i];
	}
	
	for( j=0; j<i; j++)
		preOrdem1[j] = preOrdem[j+1];
	
	for( i=i+1, j = 0 ; inOrdem[i] != NULL ; i++, j++){
		inOrdem2[j] = inOrdem[i];
	}
	
	return; 
}


int main()
{
	int nNos, numCasos;
	char preOrdem[53], inOrdem[53];
	ArvBin *arv;
	
	scanf("%d",&numCasos);
	
	while(numCasos--)
	{
		scanf("%d%s%s",&nNos,preOrdem,inOrdem);
		montaArv(&arv,preOrdem,inOrdem);
		/*arv = criaArv(1,criaArv(2,NULL,NULL),criaArv(3,NULL,NULL));*/
		
		PosOrdem(arv);
		
		free_arv(&arv);
	}
	printf("\n");
	printf("%d\n", arv);
	return 0;
}