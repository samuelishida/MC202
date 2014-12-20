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
	
	/*inicia as arvores com um unico vertice*/
	for(i=0; i<numArvs; i++)
		floresta[i] = criaArvore(i);
		
	return floresta;
}

void link(int a, int b, Arvore **floresta){
	/*liga as duas arvores*/
	floresta[a]->pai = floresta[b];
}

void cut(int a, Arvore **floresta){
	/*remove a ligacao entre as duas arvores*/
	floresta[a]->pai = NULL;
}

int lca(int a, int b, Arvore **floresta, int numArvs){
	NoArv *no;
	bool *ancestrais;
	
	/*um vetor de booleanos que indicam quem eh ancestral de a*/
	ancestrais = calloc(numArvs,sizeof(bool));
	
	no = floresta[a];
	
	/*enquanto nao chegar a raiz da arvore*/
	while(no){
		/*o vertice n eh ancestral de a*/
		ancestrais[no->n] = true;
		no=no->pai;
	}
	
	no = floresta[b];
	
	/*enquanto nao chegar na raiz e enquanto nao for ancestral*/
	while(no && !ancestrais[no->n]){
		no=no->pai;
	}
	
	free(ancestrais);
	
	/*retorna o minimo ancestral comum*/
	return no->n;
}

void liberaFloresta(Arvore **floresta, int numArvs){
	int i;
	
	for(i=0; i<numArvs; i++)
		free(floresta[i]);
	
	free(floresta);
}






