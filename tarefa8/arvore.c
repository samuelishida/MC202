/*
	Tarefa 8 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "arvore.h"

Arvore *criaArvore(int a) {
    Arvore *raiz;
	
	raiz = (Arvore *)malloc(sizeof(Arvore));
	
	raiz->pai = NULL;
	raiz->n = a;
	
	return raiz;
}

Arvore **criaFloresta(int numArvs){
	Arvore **floresta;
	int i;
	
	floresta = (Arvore **) malloc(numArvs*sizeof(Arvore *));
	
	for(i=0; i<numArvs; i++)
		floresta[i] = criaArvore(i);
		
	return floresta;
}

void link(int a, int b, Arvore **floresta){

	floresta[a]->pai = floresta[b];
}

void cut(int a, Arvore **floresta){
	
	floresta[a]->pai = NULL;
}

int lca(int a, int b, Arvore **floresta, int numArvs){
	NoArv *no;
	bool *ancestrais;
	
	ancestrais = calloc(numArvs,sizeof(bool));
	
	no = floresta[a];
	while(no){
		ancestrais[no->n] = true;
		no=no->pai;
	}
	
	no = floresta[b];
	while(no && !ancestrais[no->n]){
		no=no->pai;
	}
	
	free(ancestrais);
	
	return no->n;
}

void liberaFloresta(Arvore **floresta, int numArvs){
	int i;
	
	for(i=0; i<numArvs; i++)
		free(floresta[i]);
	
	free(floresta);
}






