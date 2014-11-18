/*
	Tarefa 7 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "estruturas.h"

NoArvBin *Remove_Aux;

lista *cria_lista()
{	
	lista *p = (lista *)malloc(sizeof(lista));

	p->prox = NULL;

	return p;
}

lista *insere_lista(lista **last, int n)
{
	lista *p = (lista *)malloc(sizeof(lista));
	
	p->n = n;
	p->prox = NULL;
	p->aloc = true;
	
	(*last)->prox = p;
	
	return p;
}

void desaloca_lista(lista **first)
{
	lista *p = *first;
	lista *aux;
	
	while(p)
	{
		aux = p;
		p = p->prox;
		free(aux);
	}
}

bool fim_lista(lista *p)
{
	return (p->prox == NULL)?(true):(false);
}

bool lista_vazia(lista **first)
{
	return ( (*first)->prox == NULL)?(true):(false);
}

ArvBin CriaArvBin ()
{
	ArvBin *p = (ArvBin*)malloc(sizof(ArvBin));
	
	(*p)->pai = NULL;
	(*p)->esq = NULL;
	(*p)->dir = NULL;
	
	return p;
}

void insere (int k, ArvBin **p, boolean *pertence)
{
	if (*p == NULL) {
		*pertence = FALSE ;
		*p = (NoArvBin *)malloc(sizeof(NoArvBin)) ;
		(*p)->chave = k ;
		(*p)->esq = NULL ;
		(*p)->dir = NULL ;
	}
	else if (k == (*p)->chave) *pertence = TRUE ;
	else if (k < (*p)->chave)
		insere (k, &(*p)->esq, pertence) ;
	else
		insere (k, &(*p)->dir, pertence) ;
}

void Remove (int k, ArvBin **p)
{
	if (*p == NULL) printf("Nao ha chave k\n") ;
	else if (k < (*p)->info) Remove (k, &(*p)->esq) ;
	else if (k > (*p)->info) Remove (k, &(*p)->dir) ;
	else { /* remover */
		Remove_Aux = *p ;
		if (Remove_Aux->dir == NULL) *p = Remove_Aux->esq ; /* soh tem um...else filho ? */
		if (Remove_Aux->esq == NULL) *p = Remove_Aux->dir ;
		else
		/* troca pelo mais a dir da subarvore esq */
		troca (&Remove_Aux->esq) ;
		free (Remove_Aux) ;
	}
}

void troca (NoArvBin **r)
{
	if ((*r)->dir != NULL) troca (&(*r)->dir) ;
	else {
		Remove_Aux->info = (*r)->info ;
		Remove_Aux = *r ;
		*r = (*r)->esq ;
	}
}

void RotDir (NoArvBin **t)
{
	NoArvBin *x = (*t); 
	NoArvBin *y = x->esq;
	
	x->esq = y->dir; 
	
	if(y->dir != NULL)
		(y->dir)->pai = x;
		
	y->pai = x->pai;
	
	if(x->pai == NULL)
		*t = y;
	else if(x == (x->pai)->dir)
		(x->pai)->dir = y;
	else
		(x->pai)->esq = y;
		
	y->dir = x;
	x->pai = y;
}

void RotEsq (NoArvBin **t)
{
	NoArvBin *x = (*t); 
	NoArvBin *y = x->dir; 
	
	x->dir = y->esq; 
	if(y->esq != NULL) 
		(y->esq)->pai = x;
	
	y->pai = x->pai;
	
	if(x->pai == NULL)
		*t = y;
	else if(x == (x->pai)->esq)
		(x->pai)->esq = y;
	else
		(x->pai)->dir = y;
	
	y->esq = x;
	x->pai = y;
}




