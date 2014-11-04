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
	char n;
	struct No *esq, *dir ;
} ArvBin, NoArvBin;

void criaNo (ArvBin **p, int x);

ArvBin *criaArv (char x, ArvBin *NoEsq, ArvBin *NoDir);

void PosOrdem (ArvBin *p);

void free_arv (ArvBin **p);

ArvBin *criaArv (char x, ArvBin *NoEsq, ArvBin *NoDir) {
	ArvBin *p = (ArvBin *)malloc(sizeof(ArvBin)) ;
	p->n = x ;
	p->esq = NoEsq ;
	p->dir = NoDir ;
	return p ;
}

void PosOrdem (ArvBin *p) {
	if (p != NULL) {
		PosOrdem (p->esq);
		PosOrdem (p->dir);
		printf ("%c", p->n);
	}
}

void free_arv (ArvBin **p) {
	if( (*p)->esq != NULL){
		free_arv (&((*p)->esq)) ;
	}
	if( (*p)->dir != NULL){
		free_arv (&((*p)->dir)) ;
	}
	free(*p);
	*p = NULL;
}

void montaArv (ArvBin **arv, char *preOrdem, char *inOrdem, int tam) {
	char preOrdem1[53], preOrdem2[53], inOrdem1[53], inOrdem2[53];
	int j, tam1, tam2;

	if(tam < 1)
		return;

	*arv = criaArv(preOrdem[0],NULL,NULL);

	if( tam == 1 )
		return;

	/* separa os subvetores */
	
	for( tam1=0 ; inOrdem[tam1] != preOrdem[0]; tam1++){
		inOrdem1[tam1] = inOrdem[tam1];
	}
	
	inOrdem1[tam1] = '\0';
	
	for( j=0; j < tam1; j++)
		preOrdem1[j] = preOrdem[j+1];
	
	preOrdem1[tam1] = '\0';
	
	montaArv(&((*arv)->esq),preOrdem1,inOrdem1,tam1);
	
	for( j=tam1+1, tam2=0; j < tam; j++, tam2++)
		preOrdem2[tam2] = preOrdem[j];
	
	preOrdem2[tam2] = '\0';
	
	for( j = 0 ; j < tam2 ; j++)
		inOrdem2[j] = inOrdem[j + tam1 + 1];
	
	inOrdem2[tam2] = '\0';
	
	montaArv(&((*arv)->dir),preOrdem2,inOrdem2,tam2);
	
	/*printf("%s %s %s %s\n",preOrdem1,preOrdem2,inOrdem1,inOrdem2);*/
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
		montaArv(&arv,preOrdem,inOrdem,nNos);
		/*arv = criaArv(1,criaArv(2,NULL,NULL),criaArv(3,NULL,NULL));*/
		
		PosOrdem(arv);
		printf("\n");
		
		free_arv(&arv);
	}
	
	return 0;
}