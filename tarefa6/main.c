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
		PosOrdem (p->esq) ;
		PosOrdem (p->dir) ;
		printf ("%c", p->n) ;	
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

void montaArv (ArvBin **arv, char *preOrdem, int tamPre, char *inOrdem, int tamIn) {
	char preOrdem1[53], preOrdem2[53], inOrdem1[53], inOrdem2[53];
	int i, j, tamPre1, tamPre2, tamIn1, tamIn2;
	
	*arv = criaArv(preOrdem[0],NULL,NULL);
	
	/* separa os subvetores */
	
	for( tamIn1=0 ; inOrdem[tamIn1] != preOrdem[0] && tamIn1 < tamIn; tamIn1++){
		inOrdem1[tamIn1] = inOrdem[tamIn1];
	}
	
	inOrdem1[tamIn1] = '\0';
	
	for( tamPre1=0; tamPre1<tamIn1; tamPre1++, tamPre1++)
		preOrdem1[tamPre1] = preOrdem[tamPre1+1];
	
	preOrdem1[tamPre1] = '\0';
	
	if(tamPre > 1 && tamIn > 1)
		montaArv(&((*arv)->esq),preOrdem1,tamPre1,inOrdem1,tamIn1);
	
	for( j=tamPre1+1, tamPre2=0; j < tamPre; j++, tamPre2++)
		preOrdem2[tamPre2] = preOrdem[j];
	
	preOrdem2[tamPre2] = '\0';
	
	for( j=tamIn1+1, tamIn2=0 ; j < tamIn ; j++, tamIn2++)
		inOrdem2[tamIn2] = inOrdem[j];
	
	inOrdem2[tamIn2] = '\0';
	
	if(tamPre > 1 && tamIn > 1)
		montaArv(&((*arv)->dir),preOrdem2,tamPre2,inOrdem2,tamIn2);
	
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
		montaArv(&arv,preOrdem,nNos,inOrdem,nNos);
		/*arv = criaArv(1,criaArv(2,NULL,NULL),criaArv(3,NULL,NULL));*/
		
		PosOrdem(arv);
		
		free_arv(&arv);
	}
	
	return 0;
}