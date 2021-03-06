/*
	Tarefa 7 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "cobertura.h"

void criaUniverso(ArvoreBin **U, int tamUniverso)
{
	int i;
	
	*U = (ArvoreBin *)criaArvoreBin();
    
   for(i = 1; i <= tamUniverso; i++)
   	insereNo(i, U);
}


void removeConjunto(ArvoreBin *M, ArvoreBin **arv) {
	int chave;
	
	if(M){
		chave = M->rotulo;
		removeNo(arv, chave);
		removeConjunto(M->esq, arv);
		removeConjunto(M->dir, arv);
	}
}

int numNos(ArvoreBin *p) {
    if(p)
        return(1 + numNos(p->esq) + numNos(p->dir));
    else
        return 0;
}

void uneConjuntos(ArvoreBin *M, ArvoreBin **R)
{
	int chave;
	
	if(M != NULL){
		chave = M->rotulo;
		insereNo(chave, R);
		uneConjuntos(M->esq, R);
		uneConjuntos(M->dir, R);
	}
}
